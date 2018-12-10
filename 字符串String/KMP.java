/**
 * KMP算法
 */
public class KMP {
    private final int R;       
    private int[][] dfa;       

    private char[] pattern;    
    private String pat;        

    /**
     * 需要处理的字符串
     *
     * @param pat 需要处理的字符串
     */
    public KMP(String pat) {
        this.R = 256;
        this.pat = pat;

        int m = pat.length();
        dfa = new int[R][m]; 
        dfa[pat.charAt(0)][0] = 1; 
        for (int x = 0, j = 1; j < m; j++) {
            for (int c = 0; c < R; c++) 
                dfa[c][j] = dfa[c][x];     
            dfa[pat.charAt(j)][j] = j+1;   
            x = dfa[pat.charAt(j)][x];    
        } 
    } 

    /**
     * 字符数组的情况
     *
     * @param pattern 需要处理的字符串
     * @param R 字母表大小
     */
    public KMP(char[] pattern, int R) {
        this.R = R;
        this.pattern = new char[pattern.length];
        for (int j = 0; j < pattern.length; j++)
            this.pattern[j] = pattern[j];

        int m = pattern.length;
        dfa = new int[R][m]; 
        dfa[pattern[0]][0] = 1; 
        for (int x = 0, j = 1; j < m; j++) {
            for (int c = 0; c < R; c++) 
                dfa[c][j] = dfa[c][x];     
            dfa[pattern[j]][j] = j+1;      
            x = dfa[pattern[j]][x];        
        } 
    } 

    /**
     * 返回文本串中第一个出现的模式字符串的索引。 
     *
     * @param  text 测试的字符串
     * @return 第一次出现的字符位置，没有发现返回-1
     */
    public int search(String txt) {
        int m = pat.length();
        int n = txt.length();
        int i, j;
        for (i = 0, j = 0; i < n && j < m; i++) {
            j = dfa[txt.charAt(i)][j];
        }
        if (j == m) 
            return i - m;    
        return -1;                   
    }

    /**
     * 返回文本串中第一个出现的模式字符串的索引。 
     *
     * @param  text 测试的字符串
     * @return 第一次出现的字符位置，没有发现返回-1
     */
    public int search(char[] text) {

        // DFA模拟操作
        int m = pattern.length;
        int n = text.length;
        int i, j;
        for (i = 0, j = 0; i < n && j < m; i++) {
            j = dfa[text[i]][j];
        }
        // 查找成功
        if (j == m) 
            return i - m;    
        // 查找失败
        return -1;                   
    }


    public static void main(String[] args) {
        String txt = "abcabcabc";
        String pat = "cabc";
        KMP kmp = new KMP(pat);
        System.out.println(kmp.search(txt));
    }
}