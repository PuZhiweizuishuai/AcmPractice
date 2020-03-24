/**
 * https://leetcode-cn.com/problems/house-robber-ii/
 */
public class HouseRobberII {
    public static void main(String[] args) {
        int[] nums = new int[] {1,2,4,5,3,1,1,3};
        System.out.println(rob(nums));;
    }

    public static int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int a = 0, b = 0, max = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            int c = Math.max(a, b + nums[i]);
            b = a;
            a = c;
        }
        b = 0;
        for (int i = 1; i < nums.length; i++) {
            int c = Math.max(max, b + nums[i]);
            b = max;
            max = c;
        }
        return Math.max(a, max);
    }
}