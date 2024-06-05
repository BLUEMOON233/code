import java.util.Arrays;
import java.util.Scanner;

public class G {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];
        for (int i = 0; i <= n - 1; i++)
            a[i] = scanner.nextInt();
        for (int i = 0; i <= n - 1; i++)
            b[i] = scanner.nextInt();
        Arrays.sort(a);
        Arrays.sort(b);
        long result = 0;
        for (int i = 1; i <= n; i++) {
            long now = 0x3f3f3f3f;
            for (int j = 0; j <= n - 1; j++)
                now = Math.min(now, Math.abs(a[j] - b[(i + j) % n]));
            result = Math.max(result, now + 1);
        }
        System.out.println(result);
    }
}
