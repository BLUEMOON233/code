package com.DivergenceSystem;

import javax.swing.table.AbstractTableModel;
import java.io.Serializable;
import java.util.List;

public class ProcessedStudent implements Serializable {
    public int number = -1;
    public String name = null;
    public String gender = null;
    public double score = 0.0;
    public String major = null;
    public int classCode = 0;

    public ProcessedStudent(int number, String name, String gender, double score, String major) {
        this.number = number;
        this.name = name;
        this.gender = gender;
        this.score = score;
        this.major = major;
    }

    public ProcessedStudent(int number, String name, String gender, double score, String major, int classCode) {
        this.number = number;
        this.name = name;
        this.gender = gender;
        this.score = score;
        this.major = major;
        this.classCode = classCode;
    }

    @Override
    public String toString() {
        return String.format("%d&%s&%s&%f&%s&%d", number, name, gender, score, major, classCode);
    }

    public static class DataTableModel extends AbstractTableModel {
        private List<ProcessedStudent> dataList;
        private String[] columnNames = {"学号", "姓名", "性别", "绩点", "专业", "班级"};

        public DataTableModel(List<ProcessedStudent> dataList) {
            this.dataList = dataList;
        }

        @Override
        public int getRowCount() {
            return dataList.size();
        }

        @Override
        public int getColumnCount() {
            return columnNames.length;
        }

        @Override
        public Object getValueAt(int row, int column) {
            ProcessedStudent data = dataList.get(row);
            switch (column) {
                case 0:
                    return data.number;
                case 1:
                    return data.name;
                case 2:
                    return data.gender;
                case 3:
                    return data.score;
                case 4:
                    return data.major;
                case 5:
                    return data.classCode;
                default:
                    return null;
            }
        }

        @Override
        public String getColumnName(int column) {
            return columnNames[column];
        }
    }
}
