#include <stdio.h>

int main(void)
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int t = sqrt(n);                   //大方块边长t
        int v = n - t * t;                 //多v个小方块
        int ans = t * (t + 1) * 2;         //大方块需要的木棍数量
        ans += v * 2 + (v != 0) + (v > t); //加上v个小方块需要的木棍数量
        //printf("(v!=0)=%d\n",v!=0);
        printf("%d\n", ans);
    }

    return 0;
}
