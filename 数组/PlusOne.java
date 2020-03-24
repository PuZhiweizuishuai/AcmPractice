/**
 * https://leetcode-cn.com/problems/plus-one/
 */
public class PlusOne {
    public static void main(String[] args) {
        int[] d = new int[] {9,9,9};
        print(plusOne(d));
    }

    public static int[] plusOne(int[] digits) {
        for (int i = digits.length-1; i >= 0; i--) {
            if (digits[i] == 9 && i != 0) {
                digits[i] = 0;
                continue;
            } else if (i == 0 && digits[i] == 9) {
                int[] d = new int[digits.length+1];
                d[0] = 1;
                return d; 
            } else {
                digits[i]++;
                break;
            }
        }
        return digits;
    }

    public static void print(int[] d) {
        for (int i = 0; i < d.length; i++) {
            System.out.print(d[i] + "   ");
        }
        System.out.println();
    }
}