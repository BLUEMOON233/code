import java.util.Arrays;
import java.util.Scanner;

public class J {

    static long getDist(long x_1, long y_1, long x_2, long y_2) {
        return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k;
        n = scanner.nextInt();
        k = scanner.nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i <= n - 1; i++)
            x[i] = scanner.nextInt();
        for (int i = 0; i <= n - 1; i++)
            y[i] = scanner.nextInt();

        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);

        boolean[] st = new boolean[n];
        Arrays.fill(st, false);

        long result = 0;
        for (int i = 0; i <= n - 1; i++) {
            int t = -1;
            for (int j = 0; j <= n - 1; j++)
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
            if (i != 0) result += dist[t];
            st[t] = true;
            for (int j = 0; j <= n - 1; j++)
                dist[j] = Math.min(dist[j], getDist(x[t], y[t], x[j], y[j]));
        }
        System.out.println(result);
    }
}
