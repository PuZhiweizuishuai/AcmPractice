import java.util.*;
import java.util.Arrays;

public class FloorTime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = 10010;
        int N, K;
        N = sc.nextInt();
        K = sc.nextInt();
        NiKeTime[] niKeTimes = new NiKeTime[M];
        int[] f = new int[M];
        boolean[] flag = new boolean[M];
        for (int i = 0; i <= N; i++) {
            flag[i] = false;
        }
        for (int i = 1; i <= K; i++) {
            int begin = sc.nextInt();
            int time = sc.nextInt();
            NiKeTime niKeTime = new NiKeTime(begin, time);
            flag[begin] = true;
            niKeTimes[i] = niKeTime;
        }
        Arrays.sort(niKeTimes, 1, K + 1);
        for (int i = 1; i <= K; i++) {
            System.out.println(niKeTimes[i].begin);
        }
        for (int i = N; i >= 1; i--) {
            if (flag[i]) {
                int t = erfen(niKeTimes, 1, K, i);
                for (int j = t; niKeTimes[j].begin == i; j++) {
                    // System.out.println(j);
                    f[i] = Math.max(f[i], f[i + niKeTimes[j].time]);

                }
            } else {
                f[i] = f[i + 1] + 1;
            }

        }
        System.out.println(f[0]);

    }

    public static int erfen(NiKeTime[] niKeTimes, int l, int r, int v) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (niKeTimes[m].begin < v) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
}

class NiKeTime implements Comparable<NiKeTime> {
    public int begin;
    public int time;

    public NiKeTime(int begin, int time) {
        this.begin = begin;
        this.time = time;
    }

    public int compareTo(NiKeTime niKeTime) {
        if (niKeTime.begin < this.begin) {
            return 1;
        } else if (niKeTime.begin > this.begin) {
            return -1;
        } else {
            return 0;
        }
    }
}