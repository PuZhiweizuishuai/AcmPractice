/**
 * LeetCode 13. 罗马数字转整数
 * https://leetcode-cn.com/problems/roman-to-integer/
*/

#include <stdio.h>
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int romanToInt(char *s)
{
    int n = 0, i = 0;
    while (*(s + i) != '\0')
    {
        if(*(s + i) == 'I' && (*(s + i + 1) == 'V' || *(s + i + 1) == 'X'))
        {
            switch(*(s + i + 1))
            {
                case 'V': n = n + V - I;
                    break;
                case 'X': n = n + X - I;
                    break;
            }
            i++;
        }
        else if(*(s + i) == 'X' && (*(s + i + 1) == 'L' || *(s + i + 1) == 'C'))
        {
            switch(*(s + i + 1))
            {
                case 'L': n = n + L - X;
                    break;
                case 'C': n = n + C - X;
                    break;
            }
            i++;
        }
        else if(*(s + i) == 'C' && (*(s + i + 1) == 'D' || *(s + i + 1) == 'M'))
        {
            switch(*(s + i + 1))
            {
                case 'D': n = n + D - C;
                    break;
                case 'M': n = n + M - C;
                    break;
            }
            i++;
        }
        else
        {
            switch(*(s + i))
            {
                case 'I': n = n + I;
                    break;
                case 'V': n = n + V;
                    break;
                case 'X': n = n + X;
                    break;
                case 'L': n = n + L;
                    break;
                case 'C': n = n + C;
                    break;
                case 'D': n = n + D;
                    break;
                case 'M': n = n + M;
                    break;
            }
        }
        i++;
    }
    return n;
}

int main(void)
{
    char s[100];
    scanf("%s", s);
    printf("%d\n", romanToInt(s));
    return 0;
}