import java.util.Arrays;
import java.util.Scanner;


/**
 * 活动安排
 */
public class GreedyActivity {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        int n = sc.nextInt();
        StartAndEnd[] greedy = new StartAndEnd[n];
        for(int i = 0; i < n; i++) {
            StartAndEnd s = new StartAndEnd();
            s.s = sc.nextInt();
            s.f = sc.nextInt();
            greedy[i] = s;
        }
        Arrays.sort(greedy);
        int j = 0;
        greedy[0].b = true;
        for(int i = 1; i < n; i++) {
            if(greedy[i].s >= greedy[j].f) {
                greedy[i].b = true;
                j = i;
            }
        }
        for(StartAndEnd s : greedy) {
            if(s.b) {
                sum++;
            }
        }
        System.out.println(sum); 
    }
}

class StartAndEnd implements Comparable<StartAndEnd> {
    public int s;
    public int f;
    public boolean b = false;

    @Override
    public int compareTo(StartAndEnd O) {
        if(this.f > O.f) {
            return 1;
        } else if(this.f < O.f) {
            return -1;
        } else {
            return 0;
        }
    } 
}
