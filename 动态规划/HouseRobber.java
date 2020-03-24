/**
 * https://leetcode-cn.com/problems/house-robber/
 */
public class HouseRobber {
    public static void main(String[] args) {
        
    }

    public static int rob(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            int c = Math.max(a, b + nums[i]);
            b = a;
            a = c;
        }
        return a;
    }   
}