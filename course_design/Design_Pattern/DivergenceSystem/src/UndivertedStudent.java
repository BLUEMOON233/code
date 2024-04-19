import java.io.Serializable;

public class UndivertedStudent implements Serializable {
    public int number = -1;
    public String name = null;
    public String gender = null;
    public double score = 0.0;
    public boolean isFill = false;
    public String major_1 = null;
    public String major_2 = null;
    public String major_3 = null;

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
}
