#include <stdio.h>
#include <stdlib.h>
/**
输出a的b次方的后三位数
*/
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

int main()
{
    long long int a,b;
    while(1)
    {
        scanf("%lld%lld",&a,&b);
        if(a == 0 && b == 0)
            break;
        printf("%lld\n",Pow(a,b,1000));
    }

    return 0;
}
