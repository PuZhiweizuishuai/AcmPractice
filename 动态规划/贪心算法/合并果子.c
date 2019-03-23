#include<stdio.h>
#include<stdlib.h>
#define MAX 10010
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

long long int power(long long int a[], int n)
{
    int i;
    long long int sum = 0, lastSum = 0;

    for(i = 1; i < n; i++)
    {
        lastSum = a[i] + a[i-1];
        a[i] = lastSum;
        
    }
    

    printf("sum=%lld  lastSum=%lld\n", sum,lastSum);
    return sum;
}


int main(void)
{
    int i,j,n;
    long long int a[MAX];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    
    qsort(a, n, sizeof(a[0]), cmp);
   
    printf("%lld\n", power(a, n));
    
    return 0;
}