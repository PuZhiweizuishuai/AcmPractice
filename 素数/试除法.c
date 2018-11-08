#include<stdio.h>

/**
 * 返回 1 n 为素数
 * 返回 0 n 不是素数
*/
int IsPrime(const int n);

int main(void)
{
    printf("%d\n", IsPrime(101));
    return 0;
}

int IsPrime(const int n)
{
    int i;
    if(n == 2)
        return 1;
    // 偶数优化
    if((n & 1) == 0)
        return 0;
    for(i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}