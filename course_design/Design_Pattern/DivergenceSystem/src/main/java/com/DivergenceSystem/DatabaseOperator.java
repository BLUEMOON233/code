package com.DivergenceSystem;

import java.sql.*;
import java.util.*;

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

    public void addUSList(List<UndivertedStudent> usList) {
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

    public List<UndivertedStudent> getUSList() {
        try {
            String sql = "select * from stu_info_with_fill";
            rs = stmt.executeQuery(sql);
            List<UndivertedStudent> usList = new ArrayList<UndivertedStudent>();
            while (rs.next()) {
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

    public List<UndivertedStudent> getMajorClass() {
        try {
            List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
            String sql = "select * from major;";
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                int code = rs.getInt("code");
                String name = rs.getString("name");
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
            String sql = "select code, name from major;";
            rs = stmt.executeQuery(sql);
            Map<String, Integer> mapMajorName2Code = new HashMap<>();
            while (rs.next()) {
                int code = rs.getInt("code");
                String name = rs.getString("name");
                mapMajorName2Code.put(name, code);
            }
            sql = String.format("update stu_info_with_fill set is_fill = %b, major_1 = '%d', major_2 = '%d', major_3 = '%d' where number = %d",
                    us.isFill, mapMajorName2Code.get(us.major_1), mapMajorName2Code.get(us.major_2), mapMajorName2Code.get(us.major_3), us.number);
            if (!us.isFill) {
                sql = String.format("update stu_info_with_fill set is_fill = false, major_1 = -1, major_2 = -1, major_3 = -1 where number = %d", us.number);
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
            while (rs.next()) {
                int code = rs.getInt("code");
                int class_number = rs.getInt("class");
                for (int index = 1; index <= class_number; index++) {
                    int class_code = 2021240000 + code * 100 + index;
                    String insert_sql = String.format("insert into class_list (code, major_code, student_number)" +
                            "values (%d, %d, %d);", class_code, code, 0);
                    sqls.add(insert_sql);
                }
            }
            for (String insert_sql : sqls) {
                stmt.executeUpdate(insert_sql);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void modifyClassNumber(List<UndivertedStudent> classNums) {
        try {
            for (UndivertedStudent singleClass : classNums) {
                String sql = String.format("update class_list set student_number = %s where code = %d", singleClass.name, singleClass.number);
                stmt.executeUpdate(sql);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<UndivertedStudent> getClassList() {
        try {
            List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
            String sql = "select * from class_list;";
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                int code = rs.getInt("code");
                int student_number = rs.getInt("student_number");
                int major_code = rs.getInt("major_code");
                ret.add(new UndivertedStudent(code, String.valueOf(student_number), String.valueOf(major_code), 0.0));
            }
            return ret;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void clearStuInfoWithFill() {
        try {
            String sql = "delete from stu_info_with_fill;";
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void diverge() {
        try {
            Random random = new Random();

            String sql = "select * from stu_info_with_fill order by score DESC;";
            rs = stmt.executeQuery(sql);
            List<UndivertedStudent> usList = new ArrayList<>();
            while (rs.next()) {
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
            //建立专业代码和名字的映射
            sql = "select code, name from major;";
            rs = stmt.executeQuery(sql);
            Map<Integer, String> mapMajorCode2Name = new HashMap<>();
            Map<String, Integer> mapMajorName2Code = new HashMap<>();
            while (rs.next()) {
                int code = rs.getInt("code");
                String name = rs.getString("name");
                mapMajorName2Code.put(name, code);
                mapMajorCode2Name.put(code, name);
            }
            //建立班级和专业的映射
            sql = "select * from class_list;";
            rs = stmt.executeQuery(sql);
            Map<Integer, Integer> mapClassCode2Number = new HashMap<>();
            Map<Integer, Integer> mapMajorCode2Number = new HashMap<>();
            Map<Integer, List<ProcessedStudent>> mapClassCode2PSList = new HashMap<>();
            Map<Integer, List<Integer>> mapMajorCode2ClassList = new HashMap<>();
            List<Integer> classList = new ArrayList<>();
            while (rs.next()) {
                int classCode = rs.getInt("code");
                int majorCode = rs.getInt("major_code");
                int student_number = rs.getInt("student_number");
                classList.add(classCode);
                mapClassCode2PSList.put(classCode, new ArrayList<>());
                if (mapMajorCode2ClassList.get(majorCode) == null)
                    mapMajorCode2ClassList.put(majorCode, new ArrayList<>());
                mapMajorCode2ClassList.get(majorCode).add(classCode);
//                mapClassCode2MajorCode.put(classCode, majorCode);
                mapClassCode2Number.put(classCode, student_number);
                mapMajorCode2Number.put(majorCode, mapMajorCode2Number.getOrDefault(majorCode, 0) + student_number);
            }
            //分流
            List<ProcessedStudent> psList = new ArrayList<>();
            for (UndivertedStudent us : usList) {
                if (!us.isFill) {
                    ProcessedStudent ps = new ProcessedStudent(us.number, us.name, us.gender, us.score, "NULL");
                    psList.add(ps);
                    continue;
                }
                int majorCode1 = Integer.parseInt(us.major_1);
                int majorCode2 = Integer.parseInt(us.major_2);
                int majorCode3 = Integer.parseInt(us.major_3);
                ProcessedStudent ps = null;
                if (mapMajorCode2Number.get(majorCode1) > 0) {
                    mapMajorCode2Number.put(majorCode1, mapMajorCode2Number.get(majorCode1) - 1);
                    ps = new ProcessedStudent(us.number, us.name, us.gender, us.score, mapMajorCode2Name.get(majorCode1));
                } else if (mapMajorCode2Number.get(majorCode2) > 0) {
                    mapMajorCode2Number.put(majorCode2, mapMajorCode2Number.get(majorCode2) - 1);
                    ps = new ProcessedStudent(us.number, us.name, us.gender, us.score, mapMajorCode2Name.get(majorCode2));
                } else if (mapMajorCode2Number.get(majorCode3) > 0) {
                    mapMajorCode2Number.put(majorCode3, mapMajorCode2Number.get(majorCode3) - 1);
                    ps = new ProcessedStudent(us.number, us.name, us.gender, us.score, mapMajorCode2Name.get(majorCode3));
                } else {
                    ps = new ProcessedStudent(us.number, us.name, us.gender, us.score, "NULL");
                }
                psList.add(ps);
            }

            for (ProcessedStudent ps : psList) {
                if (ps.major.equals("NULL")) continue;
                int majorCode = mapMajorName2Code.get(ps.major);
                List<Integer> myClassList = mapMajorCode2ClassList.get(majorCode);
                for (int myClass : myClassList)
                    if (mapClassCode2Number.get(myClass) == 0)
                        myClassList.remove(myClass);
                int randIndex = random.nextInt(myClassList.size());

                int myClass = myClassList.get(randIndex);
                mapClassCode2PSList.get(myClass).add(ps);
            }

            for (int classCode : classList) {
                List<ProcessedStudent> classPSList = mapClassCode2PSList.get(classCode);
                for (ProcessedStudent ps : classPSList) {
                    ps.classCode = classCode;
                }
            }

            for (ProcessedStudent ps : psList) {
                int majorCode = mapMajorName2Code.getOrDefault(ps.major, -1);
                sql = "insert into stu_info_processed (number, name, gender, score, major, class_code)\n" +
                        String.format("values (%d, '%s', '%s', '%f', '%d', %d);", ps.number, ps.name, ps.gender, ps.score, majorCode, ps.classCode);
                stmt.executeUpdate(sql);
            }


        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void clearStuInfoProcessed() {
        try {
            String sql = "delete from stu_info_processed;";
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<ProcessedStudent> getPSList() {
        try {
            //建立专业代码和名字的映射
            String sql = "select code, name from major;";
            rs = stmt.executeQuery(sql);
            Map<Integer, String> mapMajorCode2Name = new HashMap<>();
            while (rs.next()) {
                int code = rs.getInt("code");
                String name = rs.getString("name");
                mapMajorCode2Name.put(code, name);
            }

            sql = "select * from stu_info_processed;";
            rs = stmt.executeQuery(sql);
            List<ProcessedStudent> psList = new ArrayList<>();
            while (rs.next()) {
                int number = rs.getInt("number");
                String name = rs.getString("name");
                String gender = rs.getString("gender");
                double score = rs.getDouble("score");
                int major = rs.getInt("major");
                int classCode = rs.getInt("class_code");

                psList.add(new ProcessedStudent(number, name, gender, score, mapMajorCode2Name.getOrDefault(major, "NULL"), classCode));
            }

            return psList;
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
