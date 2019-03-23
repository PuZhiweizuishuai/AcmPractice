import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Fruit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        Queue<Integer> queue = new PriorityQueue<>();
        for(int i = 0; i < n; i++) {
            queue.add(a[i]);
        }
        for(int i = 1; i < n; i++) {
            int x = queue.remove();
            int y = queue.remove();
            queue.add(x+y);
            sum += x + y;
        }

        System.out.println(sum);
        
    }
}