#include <stdio.h>
#include <string.h>
#define max(x, y) (x > y ? x : y)
#define N 101


int main(void)
{
    int n, m, i, j, k, a[N], dp[N][N], ans = 0;
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (m = 2; m <= n; m++)
    {
        for (i = 0; i < n; i++)
        {
            j = (i + m) % n;
            if (m == 2)
                dp[i][j] = a[i] * a[j] * a[(i + 1) % n];
            else
            {
                k = (i + 1) % n;
                while (k % n != j)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                    k = (k + 1) % n;
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}