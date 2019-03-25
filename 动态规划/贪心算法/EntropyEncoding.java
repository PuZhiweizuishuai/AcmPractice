import java.util.Arrays;
import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Queue;
public class EntropyEncoding {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        while (!str.equals("END")) {
            int sum = 0;
            int length = str.length();
            int[] charNumber = new int[128];
            for(int i = 0; i < 128; i++) {
                charNumber[i] = 0;
            }
            for(int i = 0; i < length; i++) {
                charNumber[(int)str.charAt(i)]++;
            }
            Arrays.sort(charNumber);

            PriorityQueue<Integer> queue = new PriorityQueue<>();
            int num = 0;
            for(int i = 0; i < 128; i++) {
                if(charNumber[i] != 0) {
                    queue.offer(charNumber[i]);
                    num++;
                }
            } 
            // 注意判断只有一个单词的情况
            if(queue.size() != 1) {
                for(int i = 1; i < num; i++) {
                    int x = queue.poll();
                    int y = queue.poll();
                    queue.add(x+y);
                    sum += x + y;
                }    
            } else {
                sum = length;
            }    
            
            double t = (length*8.0 / sum);
            System.out.printf("%d %d %.1f\n", length*8, sum, t);
            str = sc.next();
        }
    }
}