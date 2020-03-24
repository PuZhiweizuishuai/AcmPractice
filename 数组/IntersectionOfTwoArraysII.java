import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/**
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 */
public class IntersectionOfTwoArraysII {
    public static void main(String[] args) {
        int[] nums1 = new int[] { 1, 2, 2, 1 };
        int[] nums2 = new int[] { 2, 2 };
        System.out.println(intersect(nums1, nums2));
    }

    public static int[] intersect(int[] nums1, int[] nums2) {
        // List<Integer> list = new ArrayList<>();
        // for (int i = 0; i < nums1.length; i++) {
        // for (int j = 0; j < nums2.length; j++) {
        // if (nums1[i] == nums2[j]) {
        // list.add(nums1[i]);
        // nums2[j] = -1;
        // }
        // }
        // }
        // int size = list.size();
        // int[] args = new int[size];
        // int i = 0;
        // for (Integer num : list) {
        // args[i] = num;
        // i++;
        // }

        // return args;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                nums1[k++] = nums1[i++];
                ++j;
            }
        }
        return Arrays.copyOfRange(nums1, 0, k);

    }
}