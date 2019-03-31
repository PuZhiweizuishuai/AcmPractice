import java.util.Arrays;
import java.util.Scanner;
/**
 * 这种方法有问题
 * 如果碰见比值相等的情况时，数据无法通过
 */
public class BoneCollector {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T != 0) {
            T--;
            int n = sc.nextInt();
            int v = sc.nextInt();
            int sum = 0;
            Bones[] bones = new Bones[n];
            for (int i = 0; i < n; i++) {
                bones[i] = new Bones();
                bones[i].money = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                bones[i].volume = sc.nextInt();
                bones[i].jisuan();
            }
            Arrays.sort(bones);
            for (int i = 0; i < n; i++) {
                if ((v - bones[i].volume) < 0) {
                    continue; 
                }
                v -= bones[i].volume;
                sum += bones[i].money;
            }
            System.out.println(sum);
        }
        sc.close();
    }
}

class Bones implements Comparable<Bones> {
    public int money;
    public int volume;
    public double bizhi;

    public void jisuan() {
        bizhi = (money * 1.0) / (volume * 1.0);
    }

    @Override
    public int compareTo(Bones B) {
        if (this.bizhi > B.bizhi) {
            return -1;
        } else if (this.bizhi < B.bizhi) {
            return 1;
        } else {
            return 0;
        }
    }
}