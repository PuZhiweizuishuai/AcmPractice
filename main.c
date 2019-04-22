#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))


int main(void)
{
    int i, j, N, A[20005], k;
    int dp[20005], ans = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    //printf("\n");
    ans = 0;
    for (i = 0, j = N - 1, k = 0; k < N; k++)
    {
        if (A[j]*(k+1) >= A[i]*(k+1))
        {
            //printf("%d   k=%d    %d   i=%d\n", A[i], k + 1, A[i] * (k + 1),i);
            ans += (A[i] * (k + 1));
            //printf("ans=%d\n", ans);
            i++;
        }
        else
        {
            //printf("%d   k=%d    %d   j=%d\n", A[j], k + 1, A[j] * (k + 1),j);
            ans += (A[j] * (k + 1));
            //printf("ans=%d\n", ans);
            j--;
        }
    }

    printf("%d\n", ans);

    return 0;
}
