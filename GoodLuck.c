#include <stdio.h>
int main(void)
{
    long long int n, m;
    scanf("%lld%lld", &n, &m);
    if (n % 2 == 1 && m % 2 == 0 && n < m)
    {
        printf("2\n");
        return 0;
    }
    else if (n % 2 && m % 2)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}