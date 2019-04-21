#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b
int maxWeight(int dp[], int Wi[], int Di[], int N, int M)
{
    memset(dp, 0, sizeof(dp[0]));
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = M; j >= Wi[i]; j--)
        {
            dp[j] = max(dp[j - Wi[i]] + Di[i], dp[j]);
        }
    }
    return dp[M];
}

int main(void)
{
    int i, j;
    int N, M, Wi[4000], Di[4000], dp[40000];
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%d%d", &Wi[i], &Di[i]);
    }
    printf("%d\n", maxWeight(dp, Wi, Di, N, M));

    return 0;
}