import java.util.Arrays;
import java.util.Scanner;
/**
 * 支援灾区的非背包解法
 * 对于一些特殊数据可能有问题
 */
public class HDU2191 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        int c, h, p;
        while (C != 0) {
            int sum = 0;
            int n = sc.nextInt();
            int m = sc.nextInt();
            Rice[] rice = new Rice[m];
            for (int i = 0; i < m; i++) {
                p = sc.nextInt();
                h = sc.nextInt();
                c = sc.nextInt();
                Rice r = new Rice(p, h, c);
                rice[i] = r;
            }
            Arrays.sort(rice);
            for (int i = 0; i < m; i++) {
                for(int j = 0; j < rice[i].c; j++) {
                    sum += rice[i].h;
                    n -= rice[i].p;
                    if(n <= 0) {
                        break;
                    }
                }
                if(n <= 0)
                    break;
            }
            System.out.println(sum);
            C--;
        }
        sc.close();
    }
}

class Rice implements Comparable<Rice> {
    public int p;
    public int h;
    public int c;
    public double bizhi;

    public Rice(int p, int h, int c) {
        this.p = p;
        this.h = h;
        this.c = c;
        bizhi = (h * 1.0) / (p * 1.0);
    }

    public double getbizhi() {
        return bizhi;
    }

    @Override
    public int compareTo(Rice R) {
        if (this.bizhi > R.bizhi) {
            return -1;
        } else if (this.bizhi < R.bizhi) {
            return 1;
        } else {
            return 0;
        }
    }
}