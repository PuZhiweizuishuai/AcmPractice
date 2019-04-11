#include <stdio.h>
#define N 350

int main(void)
{
    int i, j;
    int n, v[N], p[N][N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }

    return 0;
}