import java.sql.*;
import java.util.ArrayList;

public class DatabaseOperator {
    private static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DB_URL = "jdbc:mysql://42.193.107.194:3306/divergencesystem?useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC";
    private static final String USER = "DivergenceSystem";
    private static final String PASS = "admin";

    private Connection conn = null;
    private Statement stmt = null;
    public ResultSet rs = null;

    DatabaseOperator() {
        try {
            Class.forName(JDBC_DRIVER);
            conn = DriverManager.getConnection(DB_URL, USER, PASS);
            stmt = conn.createStatement();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        try {
            if (conn != null) conn.close();
            if (stmt != null) stmt.close();
            if (rs != null) rs.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public boolean addUndivertedStudent(UndivertedStudent us) {
        try {
            String sql = "select number from stu_info_with_fill where number = " + String.valueOf(us.number) + ";";
            rs = stmt.executeQuery(sql);
            if (rs.getFetchSize() > 0) return false;
            rs = null;
            if (us.isFill) {
                sql = "insert into stu_info_with_fill (number, name, gender, score, is_fill, major_1, major_2, major_3) " + "values (" + String.format("%d, '%s', '%s', %f, %b, '%s', '%s', '%s'", us.number, us.name, us.gender, us.score, us.isFill, us.major_1, us.major_2, us.major_3) + ");";
            } else {
                sql = "insert into stu_info_with_fill (number, name, gender, score, is_fill) " + "values (" + String.format("%d, '%s', '%s', %f, %b", us.number, us.name, us.gender, us.score, us.isFill) + ");";
            }
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return true;
    }

    public void delUndivertedStudent(int number) {
        try {
            String sql = "delete from stu_info_with_fill where number = " + String.valueOf(number) + ";";
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public UndivertedStudent getUndivertedStudent(int number) {
        try {
            String sql = "select * from stu_info_with_fill where number = " + String.valueOf(number) + ";";
            rs = stmt.executeQuery(sql);
            if (rs.next()) {
                UndivertedStudent us;
                String name = rs.getString("name");
                String gender = rs.getString("gender");
                double score = rs.getDouble("score");
                if (rs.getBoolean("is_fill")) {
                    String major_1 = rs.getString("major_1");
                    String major_2 = rs.getString("major_2");
                    String major_3 = rs.getString("major_3");
                    us = new UndivertedStudent(number, name, gender, score, major_1, major_2, major_3);
                } else {
                    us = new UndivertedStudent(number, name, gender, score);
                }
                return us;
            }else {
                return new UndivertedStudent(-1, "", "", 0.0);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void addUSList(ArrayList<UndivertedStudent> usList) {
        try {
            for (UndivertedStudent us : usList) {
                String sql = "select number from stu_info_with_fill where number = " + String.valueOf(us.number) + ";";
                rs = stmt.executeQuery(sql);
                if (rs.getFetchSize() > 0) continue;
                rs = null;
                if (us.isFill) {
                    sql = "insert into stu_info_with_fill (number, name, gender, score, is_fill, major_1, major_2, major_3) " + "values (" + String.format("%d, '%s', '%s', %f, %b, '%s', '%s', '%s'", us.number, us.name, us.gender, us.score, us.isFill, us.major_1, us.major_2, us.major_3) + ");";
                } else {
                    sql = "insert into stu_info_with_fill (number, name, gender, score, is_fill) " + "values (" + String.format("%d, '%s', '%s', %f, %b", us.number, us.name, us.gender, us.score, us.isFill) + ");";
                }
                stmt.executeUpdate(sql);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public String queryStudentPassword(int number) {
        try {
            String sql = "select password from student_account where number = " + String.valueOf(number) + ";";
            rs = stmt.executeQuery(sql);
            if (rs.next()) {
                String password = rs.getString("password");
                return password;
            } else {
                return "NOT FOUND";
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public static void main(String[] args) {
        UndivertedStudent us = new UndivertedStudent(2021902610, "刘文越", "男", 90);
        DatabaseOperator DO = new DatabaseOperator();
        DO.addUndivertedStudent(us);
    }
}
