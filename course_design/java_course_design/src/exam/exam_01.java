package exam;

public class exam_01 {
    public static void main(String args[]) {
        double answer = sqrt(5);
        System.out.println("最终输出结果为：");
        System.out.println(answer);
    }

    static double sqrt(double number) {
        double l = 1, r = 5;
        while(number - l * l > 1e-14) {
            double mid = (l + r) / 2;
            if(mid * mid < number) l = mid;
            else r = mid;
        }
        return l;
    }
}
