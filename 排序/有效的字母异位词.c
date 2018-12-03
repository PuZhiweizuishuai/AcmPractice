#include<stdio.h>
#include<stdbool.h>
#include<string.h>
/**
 * leetcode 242 有效的字母异位词
 * https://leetcode-cn.com/problems/valid-anagram/comments/
*/

/**
 * 希尔排序
*/
void sort(char *A, int n)
{
    int h = 0;
    int i,j;
    char get;
    while (h <= n)                        
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (i = h; i < n; i++)
        {
            j = i - h;
            get = A[i];
            while (j >= 0 && (int)A[j] > (int)get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;                 
    }		
}

bool isAnagram(char* s, char* t) {
    int i, sLength, tLength;
    sLength = strlen(s);
    tLength = strlen(t);
    if(sLength != tLength)
        return false;
    sort(s,sLength);
    sort(t, tLength);
    for(i = 0; s[i] != '\0'; i++)
        if(s[i] != t[i])
            return false;

    return true;
}



int main(void)
{
    char s[100], t[100];
    scanf("%s", s);
    scanf("%s", t);
    printf("%d\n",isAnagram(s,t));
   
    return 0;
}


/**
// 一个更加简单的java实现
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())
            return false;
        char[] as = s.toCharArray();
        char[] ts = t.toCharArray();
        Arrays.sort(as);
        Arrays.sort(ts);
        return Arrays.equals(as, ts);
    }
}
*/
