import java.math.BigInteger;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while(T-- != 0) {
            BigInteger a = scanner.nextBigInteger();
            String op = scanner.next();
            BigInteger b = scanner.nextBigInteger();
            if(op.equals("+")) {
                System.out.println(a.add(b));
            }else if(op.equals("-")) {
                System.out.println(a.subtract(b));
            }else if(op.equals("*")) {
                System.out.println(a.multiply(b));
            }else if(op.equals("/")) {
                System.out.println(a.divide(b));
            }else if(op.equals("%")) {
                System.out.println(a.remainder(b));
            }else if(op.equals("^")) {
                System.out.println(a.pow(Integer.parseInt(b.toString())));
            }
        }
    }
}
