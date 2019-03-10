#include <stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define T 100010
#define X 11
long int dp[T][X];



int main(void)
{
    long int i, j, n, time;

    while (scanf("%ld", &n))
    {
        time = 0;
        if (n == 0)
            break;
        memset(dp, 0, sizeof(dp));
        while (n--)
        {
            // 注意输入顺序
            scanf("%ld%ld", &j, &i);
            dp[i][j]++;
            time = max(i, time);
        }
        for (i = time - 1; i >= 0; i--)
        {
            for (j = 0; j <= 10; j++)
            {
                if (j == 0)
                    dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
                /*else if (j == 10)
                    dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j]);*/
                else
                    dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j - 1]));
            }
        }
        printf("%ld\n", dp[0][5]);
    }
    return 0;
}