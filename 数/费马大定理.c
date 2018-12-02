#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/**
 * x^n + y^n = z^n
 * 当整数n >2时，关于x, y, z的方程 x^n + y^n = z^n 没有正整数解
*/

/**
 * 快速幂
*/
long long int POW(const int a, const int b)
{
    if(!b)
        return 1;
    long long int t = POW(a,b>>1);
    t = t * t;
    if(b&1)
        t = t*a;
    return t;
}
 
int main(void)
{
    int x,y,n,i;
    long long int r;
    while(scanf("%d%d%d",&x,&y,&n) != EOF)
    {
        if(x == 0 && y == 0)
        {
            printf("0\n");
            continue;
        }
        if(n == 2)
        {
            r = POW(x,n) + POW(y,n);
            int a = lrint(sqrt(r));
            if(a*a == r)
                printf("%d\n",a);
            else
                printf("-1\n");
        }
        else if(n == 1)
        {
            printf("%d\n", x + y);
        }
        else
        {
            printf("-1\n");
        }
    }
 
    return 0;
}
 
/**************************************************************
    Problem: 2645
    User: 201741010102
    Language: C
    Result: Accepted
    Time:10 ms
    Memory:1088 kb
****************************************************************/
 
