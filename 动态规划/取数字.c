#include <stdio.h>
#include <string.h>
#define MAXN 200
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{
    int i, j, n, a[MAXN], k;
    int dp[MAXN][MAXN], ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(dp, 0, sizeof(dp));
    printf("\n");
    for (int k = 2; k <= n; k++)
        for (int i = 1; i <= k; i++)
        {
            dp[i][k] = max(dp[i][k - 1] + (k - 1) * a[n - k + i + 1], dp[i - 1][k - 1] + (k - 1) * a[i - 1]);
            printf("%d i=%d k=%d\n", dp[i][k],i,k);
        }
    return 0;
}