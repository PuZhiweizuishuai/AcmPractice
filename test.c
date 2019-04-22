#include <stdio.h>
#include <string.h>
#define maxn 2020
#define max(a, b) (((a) > (b)) ? (a) : (b))
long long int dp[maxn][maxn];
long long int ans;
long long int a[maxn];
int n;

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    memset(dp, 0, sizeof(dp));
    printf("\n");
    for (int k = 2; k <= n; k++)
        for (int i = 1; i <= k; i++)
        {
            dp[i][k] = max(dp[i][k - 1] + (k - 1) * a[n - k + i + 1], dp[i - 1][k - 1] + (k - 1) * a[i - 1]);
            printf("%d i=%d k=%d\n", dp[i][k],i,k);
        }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][n] + n * a[i]);
    printf("\n%lld\n", ans);
    return 0;
}
