/**
 * https://leetcode-cn.com/problems/rotate-array/
 */
public class RotateArray {
    public static void main(String[] args) {
        int[] nums = new int[] {1,2,3,4,5,6,7};
        rotate(nums, 1);
    }

    public static void rotate(int[] nums, int k) {
        int size = nums.length;
        k %= size;
        int count = 0;
        for (int i = 0; count < size; i++) {
            int current = i;
            int prev = nums[i];
            do {
                int next = (current + k) % size;
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                current = next;
                count++;
            } while (i != current);
        }
        print(nums);

    }


    public static void move(int[] nums) {
        int tmp = nums[0], t;
        int max = nums[nums.length-1];
        for (int i = 1; i < nums.length; i++) {
            t = nums[i] ;
            nums[i] = tmp;
            tmp = t;
            if (i == nums.length - 1) {
                nums[0] = max;
            }
        }
    }

    public static void print(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + "   ");
        }
        System.out.println();
    }
}