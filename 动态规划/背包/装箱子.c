#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int main(void)
{
    int i, j;
    int n, v;
    int dp[20005], w[35];
    scanf("%d%d", &v, &n);
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = v; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    printf("%d\n", v - dp[v]);
    return 0;
}