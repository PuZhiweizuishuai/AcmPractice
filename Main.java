import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        BigInteger zero = new BigInteger("0");
        BigInteger yu = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        BigInteger ten = new BigInteger("10000000007");
        for (int i = 1; i <= N; i++) {
            BigInteger B = sc.nextBigInteger();
            yu = yu.multiply(two);
            yu = yu.subtract(B);
            //
            // System.out.println(yu.toString());
            if (yu.compareTo(zero) == -1) {
                System.out.println("error");
                return;
            }

        }
        yu = yu.mod(ten);
        System.out.println(yu.toString());

    }
}