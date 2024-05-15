import javax.swing.table.AbstractTableModel;
import java.io.Serializable;
import java.util.List;

public class UndivertedStudent implements Serializable {
    public int number = -1;
    public String name = null;
    public String gender = null;
    public double score = 0.0;
    public boolean isFill = false;
    public String major_1 = "-1";
    public String major_2 = "-1";
    public String major_3 = "-1";

    UndivertedStudent(int number, String name, String gender, double score) {
        this.number = number;
        this.name = name;
        this.gender = gender;
        this.score = score;
        isFill = false;
    }

    UndivertedStudent(int number, String name, String gender, double score, String major_1, String major_2, String major_3) {
        this.number = number;
        this.name = name;
        this.gender = gender;
        this.score = score;
        isFill = true;
        this.major_1 = major_1;
        this.major_2 = major_2;
        this.major_3 = major_3;
    }

    @Override
    public String toString() {
        return String.format("%d&%s&%s&%f&%b&%s&%s&%s", number, name, gender, score, isFill, major_1, major_2, major_3);
    }

    static class DataTableModel extends AbstractTableModel {
        private List<UndivertedStudent> dataList;
        private String[] columnNames = {"Number", "Name", "Gender", "Score", "Is Fill", "Major 1", "Major 2", "Major 3"};

        DataTableModel(List<UndivertedStudent> dataList) {
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
            UndivertedStudent data = dataList.get(row);
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
                    return data.isFill;
                case 5:
                    return data.major_1;
                case 6:
                    return data.major_2;
                case 7:
                    return data.major_3;
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

