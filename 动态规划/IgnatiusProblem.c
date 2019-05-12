#include <stdio.h>
#include <string.h>
long int dp[400000];
void Sum()
{
    long int i, j;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (i = 1; i <= 120; i++)
    {
        for (j = i; j < 400000; j++)
            dp[j] += dp[j - i];
    }
}

int main(void)
{
    long int n;
    Sum();
    while (scanf("%ld", &n) != EOF)
    {
        printf("%ld\n", dp[n]);
    }

    return 0;
}