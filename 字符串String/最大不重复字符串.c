#include <stdio.h>
#include <stdlib.h>
/**
 * Longest substring
 * 最大不重复字符串
 * leetcode 第三题
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/
int length(char* s);
int Max(int a, int b);

int main()
{
    char str[100];
    scanf("%s",str);
    printf("%d",length(str));
    return 0;
}

int length(char* s)
{
    int i, j, count = 0, str[128] = {0};
    for(i = 0, j = 0; s[j] != '\0'; j++)
    {
        i = Max(str[(int)s[j]], i);
        count = Max(count, j - i + 1);
        str[(int)s[j]] = j + 1;
    }
    return count;
}

int Max(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}