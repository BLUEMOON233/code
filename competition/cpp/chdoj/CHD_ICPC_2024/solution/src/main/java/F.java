import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class F {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Set<Integer> set = new TreeSet<>();
        for (int i = 1; i <= n; i++) {
            set.add(scanner.nextInt());
        }
        int now = 0;
        for (Integer val : set) {
            if (val == now++) continue;
            System.out.println(now - 1);
            return;
        }
        System.out.println(now);
    }
}
