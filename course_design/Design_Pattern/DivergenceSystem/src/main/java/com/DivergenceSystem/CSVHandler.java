package com.DivergenceSystem;

import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

import com.csvreader.*;

public class CSVHandler {
    // 导入CSV文件
    public static List<UndivertedStudent> importCSV(String csvFilePath) {
        List<UndivertedStudent> uslist = new ArrayList<>();

        try {
            CsvReader csvReader = new CsvReader(csvFilePath, ',' ,StandardCharsets.UTF_8);
            csvReader.readHeaders();

            while (csvReader.readRecord()) {
                int number = Integer.parseInt(csvReader.get("number"));
                String name = csvReader.get("name");
                String gender = csvReader.get("gender");
                double score = Double.parseDouble(csvReader.get("score"));
                int isFill = Integer.parseInt(csvReader.get("is_fill"));
                String major1 = csvReader.get("major_1");
                String major2 = csvReader.get("major_2");
                String major3 = csvReader.get("major_3");
                UndivertedStudent us = null;
                if (isFill == 1) us = new UndivertedStudent(number, name, gender, score, major1, major2, major3);
                else us = new UndivertedStudent(number, name, gender, score);
                uslist.add(us);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return uslist;
    }

    // 导出CSV文件
    public static void exportCSV(List<UndivertedStudent> usList, String csvFilePath) {
        try {
            CsvWriter csvWriter = new CsvWriter(csvFilePath, ',', StandardCharsets.UTF_8);
            csvWriter.writeRecord(new String[]{"number", "name", "gender", "score", "is_fill", "major_1", "major_2", "major_3"});

            for (UndivertedStudent us : usList) {
                String[] contents = {String.valueOf(us.number), us.name, us.gender, String.valueOf(us.score),
                        String.valueOf(us.isFill ? 1 : 0), String.valueOf(us.isFill ? us.major_1 : -1), String.valueOf(us.isFill ? us.major_2 : -1), String.valueOf(us.isFill ? us.major_3 : -1)};
                csvWriter.writeRecord(contents);
            }
            csvWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void exportCSV(String csvFilePath, List<ProcessedStudent> psList) {
        try {
            CsvWriter csvWriter = new CsvWriter(csvFilePath, ',', StandardCharsets.UTF_8);
            csvWriter.writeRecord(new String[]{"number", "name", "gender", "score", "major", "class_code"});

            for (ProcessedStudent ps : psList) {
                String[] contents = {String.valueOf(ps.number), ps.name, ps.gender, String.valueOf(ps.score), ps.major, String.valueOf(ps.classCode)};
                csvWriter.writeRecord(contents);
            }
            csvWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}