#include <stdio.h>
#include <string.h>
#include <math.h>

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int main(void)
{
    int n, k, dp[25][550], i, j, h, s, t, x;
    while (scanf("%d%d", &n, &k))
    {
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= k; i++)
        {
            scanf("%d", &x);
            dp[1][x] = 1;
        }
        for (i = 2; i <= n; i++)
        {
            for (j = 1; j <= k; j++)
            {
                scanf("%d", &x);
                s = 99999;
                for (h = 1; h <= 500; h++)
                {
                    if (dp[i - 1][h] != 0)
                    {
                        t = dp[i - 1][h] + abs(x - h);
                        s = min(s, t);
                    }
                }
                dp[i][x] = s;
            }
        }
        s = 99999;
        for (h = 1; h <= 500; h++)
        {
            if (dp[n][h] != 0)
            {
                printf("%d    ", dp[n][h]);
                s = min(dp[n][h], s);
            }
        }
        printf("\n%d\n", s);
    }

    return 0;
}