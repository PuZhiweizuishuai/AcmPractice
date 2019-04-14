#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b
int main(void)
{
    int i, j;
    int N, m;
    int v[30050], p[30050], dp[100000005];
    scanf("%d%d", &N, &m);
    memset(dp, 0, sizeof(dp[0]));
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &v[i], &p[i]);
    }
    for (i = 0; i < m; i++)
    {
        for (j = N - 1; j >= 0; j--)
        {
            if (j - v[i] > 0)
                dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
        }
    }
    printf("%d\n", dp[N - 1]);
    return 0;
}