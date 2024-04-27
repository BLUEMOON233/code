import java.sql.*;
import java.util.ArrayList;
import java.util.List;

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
            } else {
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

    public List<UndivertedStudent> getUSList () {
        try{
            String sql = "select * from stu_info_with_fill";
            stmt.executeQuery(sql);
            List<UndivertedStudent> usList = new ArrayList<UndivertedStudent>();
            while(rs.next()) {
                UndivertedStudent us;
                int number = rs.getInt("number");
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
                usList.add(us);
            }
            return usList;
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

    public String queryAdminPassword(int number) {
        try {
            String sql = "select password from admin_account where number = " + String.valueOf(number) + ";";
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

    public String queryMajor() {
        try {
            StringBuilder sb = new StringBuilder();
            String sql = "select name from major;";
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                sb.append(rs.getString("name"));
                sb.append('+');
            }
            sb.deleteCharAt(sb.length() - 1);
            return sb.toString();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<UndivertedStudent> getMajorClass() {
        try {
            List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
            String sql = "select * from major;";
            rs = stmt.executeQuery(sql);
            while(rs.next()) {
                int code = rs.getInt("code");
                String name =  rs.getString("name");
                int class_number = rs.getInt("class");
                ret.add(new UndivertedStudent(code, name, String.valueOf(class_number), 0.0));
            }
            return ret;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void addMajor(String majorName) {
        try {
            String sql = """
                SELECT Min(T1.code) + 1 minCode FROM major T1
                WHERE (T1.code + 1) NOT IN (SELECT T2.code FROM major T2)
                AND EXISTS (SELECT T3.code FROM major T3 WHERE T3.code = 1)""";
            rs = stmt.executeQuery(sql);
            rs.next();
            int number = rs.getInt("minCode");
            sql = String.format("insert into major (code, name, class) values (%d, '%s', 0);", number, majorName);
            System.out.println(sql);
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void delMajor(int code) {
        try {
            String sql = String.format("delete from major where code = %d;", code);
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void modifyMajor(int code, int class_number) {
        try {
            String sql = String.format("update major set class = %d where code = %d;", class_number, code);
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void modifyUndivertedStudent(UndivertedStudent us) {
        try {

            String sql = String.format("update stu_info_with_fill set is_fill = %b, major_1 = '%s', major_2 = '%s', major_3 = '%s' where number = %d",
                    us.isFill, us.major_1, us.major_2, us.major_3, us.number);
            if(!us.isFill) {
                sql = String.format("update stu_info_with_fill set is_fill = false, major_1 = NULL, major_2 = NULL, major_3 = NULL where number = %d", us.number);
            }
            System.out.println(sql);
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void initClass() {
        try {
            String sql = "delete from class_list;";
            stmt.executeUpdate(sql);
            sql = "select code, class from major;";
            rs = stmt.executeQuery(sql);
            List<String> sqls = new ArrayList<>();
            while(rs.next()) {
                int code = rs.getInt("code");
                int class_number = rs.getInt("class");
                for(int index = 1; index <= class_number; index++) {
                    int class_code = 2021240000 + code * 100 + index;
                    String insert_sql = String.format("insert into class_list (code, major_code, student_number)" +
                            "values (%d, %d, %d);", class_code, code, 0);
                    sqls.add(insert_sql);
                }
            }
            for(String insert_sql : sqls) {
                stmt.executeUpdate(insert_sql);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<UndivertedStudent> getClassList() {
        try {
            List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
            String sql = "select code, student_number from class_list;";
            rs = stmt.executeQuery(sql);
            while(rs.next()) {
                int code = rs.getInt("code");
                int student_number = rs.getInt("student_number");
                ret.add(new UndivertedStudent(code, String.valueOf(student_number), "", 0.0));
            }
            return ret;
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
