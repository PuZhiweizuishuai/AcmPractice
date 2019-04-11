import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static int[] ID = new int[4000010];

    public static void init(int n) {
        for (int i = 0; i < n; i++) {
            ID[i] = -1;
        }
    }

    public static int find(int p) {
        while (ID[p] != -1) {
            p = ID[p];
        }
        return p;
    }

    public static void unions(int p, int q) {
        if (p == q)
            return;
        ID[p] = q;
    }

    public static int connected(int p, int q) {
        if (p == q)
            return 1;
        else
            return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] number = new int[4000010];
        int sum = 0;
        int n = sc.nextInt();
        int m = sc.nextInt();
        init(n);
        for (int i = 0; i < m; i++) {
            int op = sc.nextInt();
            int u = sc.nextInt();
            int v = sc.nextInt();
            int p = find(u);
            int q = find(v);
            if (op == 0) {
                if (connected(p, q) == 1) {
                    continue;
                } else {
                    unions(p, q);
                }
            } else {
                if (connected(p, q) == 1) {
                    number[sum] = 1;
                } else {
                    number[sum] = 0;
                }
                sum++;
            }
        }
        System.out.println(bigNumber(number, sum).toString());
        sc.close();
    }

    public static BigInteger bigNumber(int number[], int sum) {
        BigInteger big = new BigInteger("0");
        BigInteger two = new BigInteger("2");
        for (int i = 0; i < sum; i++) {
            if (number[i] != 0) {
                big = big.add(two.pow(sum - i - 1));
            }
        }
        BigInteger m = new BigInteger("998244353");
        big.mod(m);
        return big;
    }
}