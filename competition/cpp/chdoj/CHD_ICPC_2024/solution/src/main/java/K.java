import java.util.*;

public class K {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int n = scanner.nextInt();
        Map<String, Boolean> map = new TreeMap<>();

        Set<Integer> lens = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            String token = scanner.next();
            lens.add(token.length());
            map.put(token, true);
        }

        Map<Integer, Integer> censored = new HashMap<>();
        for (int i = 0; i <= s.length() - 1; i++) {
            StringBuilder sb = new StringBuilder();
            int lst = i;
            for (int len : lens) {
                for (int j = lst; j <= i + len - 1 && j <= s.length() - 1; j++) {
                    sb.append(s.charAt(j));
                }
                lst += len;
                boolean flag = map.getOrDefault(sb.toString(), false);
                if (flag) {
                    censored.put(i, len);
                    i += len - 1;
                    break;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i <= s.length() - 1; i++) {
            int len = censored.getOrDefault(i, -1);
            if (len != -1) {
                sb.append("<censored>");
                i += len - 1;
                continue;
            }
            sb.append(s.charAt(i));
        }
        System.out.println(sb.toString());
    }
}
