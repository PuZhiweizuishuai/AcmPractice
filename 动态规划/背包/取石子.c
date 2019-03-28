#include <stdio.h>
#include <stdlib.h>
#define MAX 220
int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main(void)
{
    int i, j;
    int n, m, k, a[MAX];
    int sum = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (i = 0; i < n; i++)
    {
        if (i > m)
            break;
        if (sum + a[i] > k)
            continue;
        sum += a[i];
    }
    printf("%d\n", sum);
    return 0;
}