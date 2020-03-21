/**
 * https://www.lintcode.com/problem/find-letter/description
 */
public class FindLetter1820 {
    public static void main(String[] args) {
        String str = "aAbBcd";
        // 第一遍解法
        // int length = str.length();
        // int[][] ch = new int[2][26];
        // for (int i = 0; i < length; i++) {
        //     if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
        //         ch[0][str.charAt(i) - 'a'] = 1;
        //     } else {
        //         ch[1][str.charAt(i) - 'A'] = 1;
        //     }
        // }
        // for (int i = 25; i >= 0; i--) {
        //     if (ch[0][i] == 1 && ch[1][i] == 1) {
        //         System.out.println((char) (i + (int) 'A'));
        //         break;
        //     }
        // }
        // 答案解法
        int length = str.length();
        int[] arrays = new int[128];
        for (int i = 0; i < length; i++) {
            arrays[str.charAt(i)]++;
        }
        // Z -> A
        // Z = 90 A = 65
        for (int i = 90; i >= 65; i--) {
            if (arrays[i] != 0 && arrays[i+32] != 0) {
                System.out.println((char) i);
                break;
            }
        }
        System.out.println("~");
    }
}