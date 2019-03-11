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
    int N, K, dp[25][550], i, j, x, h, t, s;
    while (scanf("%d%d", &N, &K) != EOF)
    {
        memset(dp, 9999, sizeof(dp));
        for (i = 1; i <= K; i++)
        {
            scanf("%d", &x);
            dp[1][x] = 1;
        }
        for (i = 2; i <= N; i++)
        {
            for (j = 1; j <= K; j++)
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
        s = 9999;
        for (h = 1; h <= 500; h++)
        {
            if (dp[N][h] != 0)
            {
                //printf("%d    ",dp[N][h]); 
                s = min(dp[N][h], s);
            }   
        }
        printf("%d\n",s-1);
    }

    return 0;
}