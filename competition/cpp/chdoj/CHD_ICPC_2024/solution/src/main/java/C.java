import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        long result = 0;
        for(int i = 1; i <= n; i++) {
            result += n / i;
        }
        System.out.println(result);
    }
}
