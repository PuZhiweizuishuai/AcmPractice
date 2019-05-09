#include <stdio.h>

int main(void)
{
    long int dp[400000], i, j, n;
    dp[0] = 1;
    for (i = 1; i <= 3; i++)
    {
        for (j = i; j < 400000; j++)
            dp[j] += dp[j - i];
    }
    while (scanf("%ld", &n) != EOF)
    {
        printf("%ld\n", dp[n]);
    }

    return 0;
}