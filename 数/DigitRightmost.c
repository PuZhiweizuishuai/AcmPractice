#include <stdio.h>
#include <stdlib.h>

long long int Pow(long long int a, long long int b, const long long int n)
{
    long long int t;
    for (t = 1; b; b >>= 1)
    {
        if (b & 1)
            t = t * a % n;
        a = a * a % n;
    }
    return t;
}

int main(void)
{
    long long int a,T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&a);
        printf("%lld\n",Pow(a,a,10));
    }

    return 0;
}
