import java.util.Arrays;
import java.util.Scanner;

public class H {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n];
        for (int i = 0; i <= n - 1; i++)
            a[i] = scanner.nextInt();

        if (n == 1) {
            System.out.println(0);
            return;
        }

        if (n == 2) {
            System.out.println(Math.min(a[0], a[1]));
            return;
        }

        Arrays.sort(a);
        long total = 0;
        for (int i = 0; i <= n - 2; i++)
            total += a[i];

        if (a[n - 1] <= total) {
            System.out.println((total + a[n - 1]) / 2);
        } else {
            System.out.println(total);
        }
    }
}
