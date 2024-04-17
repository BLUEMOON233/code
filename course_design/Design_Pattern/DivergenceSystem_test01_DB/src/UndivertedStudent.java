public class UndivertedStudent {
    public int number = -1;
    public String name = null;
    public String gender = null;
    public boolean isFill = false;
    public String major_1 = null;
    public String major_2 = null;
    public String major_3 = null;

    UndivertedStudent(int number, String name, String gender) {
        this.number = number;
        this.name = name;
        this.gender = gender;
        isFill = false;
    }

    UndivertedStudent(int number, String name, String gender, String major_1, String major_2, String major_3) {
        this.number = number;
        this.name = name;
        this.gender = gender;
        isFill = true;
        this.major_1 = major_1;
        this.major_2 = major_2;
        this.major_3 = major_3;
    }

    @Override
    public String toString() {
        return String.valueOf(number) + '&' + name + '&' + gender + '&' + String.valueOf(isFill) + '&' + major_1 + '&' + major_2 + '&' + major_3;
    }
}
