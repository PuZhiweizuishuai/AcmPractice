import java.util.HashSet;
import java.util.Set;
/**
 * https://leetcode-cn.com/problems/contains-duplicate/
 */
public class ContainsDuplicate {
    public static void main(String[] args) {
        
    }

    public static boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                return false;
            } else {
                set.add(nums[i]);
            }
        }
        return true;
    }
}