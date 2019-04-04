#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define S 100
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main(void)
{
    int i, j, m, n, MN;
    int a[MAX];
    int sumDown;
    int index = 0;
    double heigh, v;
    while (1)
    {
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0)
            break;
        MN = m * n;
        for (i = 0; i < MN; i++)
        {
            scanf("%d", &a[i]);
        }
        scanf("%lf", &v);
        index++;
        printf("%d\n", index);
        sumDown = 1;
        if (m == 1 && n == 1 && v == 0 && a[0] == 1)
        {
            printf("1.00\n100.00\n\n");
            continue;
        }
        qsort(a, MN, sizeof(a[0]), cmp);

        heigh = a[0];
        for (i = 1; i < MN; i++)
        {
            if ((a[i] - a[i - 1]) * i *S < v)
            {
                v -= (a[i] - a[i - 1]) * i *S;
                heigh = a[i];
                sumDown++;
            }
            else
            {
                heigh += v / (S*i * 1.0);
                v = 0;
                break;
            }
        }
        if (v != 0)
        {
            heigh += v / (S*MN * 1.0);
        }
        printf("%.2lf\n%.2lf\n\n", heigh, ((sumDown * 100.0) / (MN * 1.0)));
    }
    return 0;
}