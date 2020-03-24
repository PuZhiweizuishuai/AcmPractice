import java.util.Arrays;
/**
 * https://leetcode-cn.com/problems/single-number/
 */
public class SingleNumber {
    public static void main(String[] args) {
        int[] nums = new int[] { 4, 1, 2, 1, 2 };
        // 1 1 2 2 4
        System.out.println(xorSingleNumber(nums));
    }

    public static int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        Arrays.sort(nums);
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[nums.length - 1] != nums[nums.length - 2]) {
            return nums[nums.length - 1];
        }
        for (int i = 2; i < nums.length; i++) {
            if (nums[i - 1] != nums[i] && nums[i - 2] != nums[i - 1]) {
                return nums[i - 1];
            }
        }
        return -1;
    }

    public static int xorSingleNumber(int[] nums) {
        int a = 0;
        for (int i = 0; i < nums.length; i++) {
            a = a ^ nums[i];
        }
        return a;
    }
}