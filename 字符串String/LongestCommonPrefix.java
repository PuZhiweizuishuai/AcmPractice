/**
 * @author PuZhiwei
 * LeetCode 14.最长公共前缀
 * https://leetcode-cn.com/problems/longest-common-prefix/
 */
public class LongestCommonPrefix {
    public static void main(String[] args) {
        String[] str = { "abcfbc", "abfcab"};
        System.out.println(longestCommonPrefix(str));
    }

    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 1) {
            return strs[0];
        }
        StringBuilder strPrefix = new StringBuilder();
        // 不加 if 判断会出现 strs.length 为 0 的情况，直接导致数组越界
        if (strs.length > 1) {
            int len = strs[0].length();
            for (int i = 0; i < len; i++) {
                char curr = strs[0].charAt(i);

                for (int j = 1; j < strs.length; j++) {
                    // 如果碰到不同的字符直接返回
                    if (strs[j].length() <= i || strs[j].charAt(i) != curr) {
                        return strPrefix.toString();
                    }
                    if (strs[j].charAt(i) == curr && j == strs.length - 1) {
                        strPrefix.append(curr);
                    }
                }
            }
        }
        return strPrefix.toString();
    }
}