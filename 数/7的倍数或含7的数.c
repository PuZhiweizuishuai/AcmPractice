#include<stdio.h>
/**
 * 输出 n 以内 7 的倍数或含 7 的数
*/
int main(void)
{
    long long int N, i;
    scanf("%lld", &N);
    for(i = 1; i <= N; i++)
    {
        if(i % 7 == 0)
            printf("%lld ",i);
        else
        {
            int a = i;
            while(a)
            {
                if(a % 10 == 7)
                {
                    printf("%lld ", i);
                    break;
                }
                a /= 10;
            }
        }
    }
    return 0;
}
