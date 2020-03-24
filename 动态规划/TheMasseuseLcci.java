/**
 * https://leetcode-cn.com/problems/the-masseuse-lcci/
 */
public class TheMasseuseLcci {
    public static void main(String[] args) {
        int[] nums = new int[] {2,1,4,5,3,1,1,3};
        System.out.println(massage(nums));;
    }

    public static int massage(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            int c = Math.max(a, b + nums[i]);
            b = a;
            a = c;
        }
       

        return a;
    }
}