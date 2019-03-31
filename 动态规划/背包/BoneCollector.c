#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11000
#define max(a, b) a > b ? a : b
int main(void)
{
    int T, i, j;
    int n, v, boneNumber[MAX], boneVolume[MAX];
    int dp[MAX];
    scanf("%d", &T);
    while (T--)
    {
        memset(dp, 0, sizeof(dp));

        scanf("%d%d", &n, &v);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &boneNumber[i]);
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &boneVolume[i]);
        }
        for (i = 0; i < n; i++)
        {
            for (j = v; j >= boneVolume[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - boneVolume[i]] + boneNumber[i]);
                //printf("dp[%d]=%d\n",j, dp[j]);
            }
        }
        printf("%d\n", dp[v]);
    }
    return 0;
}