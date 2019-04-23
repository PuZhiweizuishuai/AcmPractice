#include <stdio.h>
#include <string.h>
#define MAXN 2005
#define max(a, b) (((a) > (b)) ? (a) : (b))
int i, j, n, A[MAXN], k;
int dp[MAXN][MAXN], ans = 0;
int main(void)
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    memset(dp, 0, sizeof(dp));
    //printf("\n");
    for (k = 2; k <= n; k++)
    {
        for (i = 1; i <= k; i++)
        {
            dp[i][k] = max(dp[i][k - 1] + (k - 1) * A[n - k + i + 1], dp[i - 1][k - 1] + (k - 1) * A[i - 1]);
            //printf("%d i=%d k=%d\n", dp[i][k], i, k);
        }
    }

    /*for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%3d    ", dp[i][j]);
        }
        printf("\n");
    }*/

    for (i = 1; i <= n; i++)
        ans = max(ans, dp[i][n] + n * A[i]);
    printf("%d\n", ans);
    return 0;
}