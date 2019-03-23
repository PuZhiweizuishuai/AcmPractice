#include<stdio.h>
#include <stdlib.h>
#define MAX 10010
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int cmp2(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int Abs(int a, int b) 
{
    if(a - b < 0) 
        return b-a;
    return a-b;
}

int maxAbs(int a[], int b[], int n)
{
    int i,j,sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += Abs(a[i], b[i]);
    }
    return sum;
}



int main(void)
{
    int i, j, n;
    int a[MAX], b[MAX];

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);
    qsort(a, n, sizeof(a[0]), cmp);
    qsort(b, n, sizeof(b[0]), cmp2);
    printf("%d\n", maxAbs(a,b,n));

    return 0;
}