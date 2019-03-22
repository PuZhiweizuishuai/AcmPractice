#include <stdio.h>
#include <stdlib.h>
#define MAX 1010
int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int Match(int tianji[], int qiwang[], int n)
{
    int jiHorse = 0;
    int i, j, sum;
    i = j = 0;
    sum = 0;
    int k = n - 1;
    int f = n - 1;
    while (1)
    {
        if (jiHorse == n)
            break; 
        if (qiwang[j] > tianji[i])
        {
            sum -= 200;
            j++;
            k--;
            jiHorse++;
            continue;
        } 
        if (qiwang[j] == tianji[i])
        { 
            if (qiwang[f] < tianji[k])
            {
                f--;
                k--;
                sum += 200;
                jiHorse++;
                continue;
            } 
            if (qiwang[j] > tianji[k])
            {
                sum -= 200;
                k--;
                j++;
                jiHorse++;
            }
            else
            {
                k--;
                j++;
                jiHorse++;
            }
            continue;
        }
        if (qiwang[j] < tianji[i])
        {
            sum += 200;
            j++;
            i++;
            jiHorse++;
            continue;
        } 
    }
    return sum;
}

int main(void)
{
    int n, i;
    int tianji[MAX], qiwang[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &tianji[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &qiwang[i]);

    qsort(tianji, n, sizeof(tianji[0]), cmp);
    qsort(qiwang, n, sizeof(qiwang[0]), cmp);


    printf("%d", Match(tianji, qiwang, n));

    return 0;
}