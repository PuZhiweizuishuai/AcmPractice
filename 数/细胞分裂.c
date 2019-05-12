#include <stdio.h>
#include <string.h>
const long long int MOD = 1000000007;

int main(void)
{
    long long int n, b, i, ans = 1, max = 0;
    long long int a[100005];
    scanf("%lld", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    int flag = 0;
    max *= 2;
    for (i = 0; i < n; i++)
    {
        if (flag)
        {
            ans = (ans * 2 % MOD - a[i] % MOD + MOD) % MOD;
        }
        else
        {
            ans *= 2;
            if (ans >= max)
            {
                flag = 1;
            }
            ans -= a[i];
            if (ans < 0)
            {
                printf("error\n");
                return 0;
            }
        }
    }
    printf("%lld\n", ans % MOD);

    return 0;
}