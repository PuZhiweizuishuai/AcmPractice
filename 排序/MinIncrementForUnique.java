/**
 * https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
 */

public class MinIncrementForUnique {
    public static void main(String[] args) {
        int[] a = new int[] {3,2,1,2,1,7};
        System.out.println(minIncrementForUnique(a));

    }

    public static int minIncrementForUnique(int[] A) {
        int min, tmp;
        // 选择排序
        for (int i = 0; i < A.length - 1; i++) {
            // 查找最小值
            min = i;
            for (int j = i + 1; j < A.length; j++) {
                if (A[j] < A[min]) {
                    min = j;
                }
            }
            if (min != i) {
                tmp = A[min];
                A[min] = A[i];
                A[i] = tmp;
            }
        }
        return count;

    }
}