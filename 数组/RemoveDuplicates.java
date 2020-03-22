/**
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

public class RemoveDuplicates {
    public static void main(String[] args) {
        int[] nums = new int[] {0,1,1,1,2,2,3,3,4};
        System.out.println(removeDuplicates(nums));
    }

    public static int removeDuplicates(int[] nums) {
        int i = 0, j = 1;
        while(j < nums.length) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
}