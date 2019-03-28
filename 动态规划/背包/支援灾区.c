#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 110
#define max(a, b) a > b ? a : b
int main(void)
{
    int i, j, k;
    int C, n, m;
    int p[MAX], h[MAX], c[MAX];
    int sum[10000];
    scanf("%d", &C);
    while (C--)
    {
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &m);
        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &p[i], &h[i], &c[i]);
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < c[i]; j++)
            {
                for (k = n; k >= p[i]; k--)
                {
                    sum[k] = max(sum[k], sum[k - p[i]] + h[i]);
                    printf("i=%d   j=%d   sum[%d]=%d\n",i,j, k, sum[k]);
                }
            }
        }
        printf("%d\n", sum[n]);
    }

    return 0;
}