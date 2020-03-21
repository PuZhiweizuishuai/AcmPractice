
/**
 * https://www.lintcode.com/problem/minimum-moves/?_from=ladder&&fromId=143
 * 
 */
public class MinimumMove1822 {
    public static void main(String[] args) {
        String s = "BAAABAB";
        int length = s.length();
        int[] aRigthCount = new int[length];
        int[] bLiftCount = new int[length];
        int count = 0, cnt = Integer.MAX_VALUE;
        // 左侧 B
        for (int i = 0; i < length; i++) {
            if (s.charAt(i) == 'B') {
                bLiftCount[i] = count;
                count++;
            } else {
                bLiftCount[i] = count;
            }
            
        }
        // 右侧 A
        count = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (s.charAt(i) == 'A') {
                aRigthCount[i] = count;
                count++;
            } else {
                aRigthCount[i] = count;
            }
            cnt = Math.min(cnt, aRigthCount[i] + bLiftCount[i]);
        }
        // 这个for循环可以移动到上面
        // for (int i = 0; i < length; i++) {
        //     System.out.println(aRigthCount[i] + "        " + bLiftCount[i]);
        //     cnt = Math.min(cnt, aRigthCount[i] + bLiftCount[i]);
        // }
        System.out.println(cnt);
    }
}