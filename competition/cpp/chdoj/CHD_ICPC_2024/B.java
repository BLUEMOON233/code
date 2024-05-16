import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long mod = scanner.nextLong();

        long[] array = new long[n];
        for (int i = 0; i <= n - 1; i++) array[i] = scanner.nextLong();
        for (int i = 0; i <= n - 1; i++) array[i] %= mod;
        Arrays.sort(array);
        BigInteger sum = BigInteger.valueOf(0);
        for(long val : array) sum = sum.add(BigInteger.valueOf(val * (n - 1)));
        for (int l = 0, r = n - 1; l <= n - 2; l++) {
            while (array[r] + array[l] >= mod && l < r) r--;
            sum = sum.subtract(BigInteger.valueOf(mod * (n - 1 - Math.max(l, r))));
        }
        System.out.println(sum);
    }
}
