#include<stdio.h>
#define N 100010
int main(void)
{
    long long int i, j, n, sum = 0;
    long long a[N], M, sumNow = 0;
    scanf("%lld%lld", &n, &M);
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        sumNow += a[i];
        if(sumNow > M)
        {
            sum++;
            sumNow = a[i];
        } 
        else if(sumNow == M)
        {
            sumNow = 0;
            sum++;
        } 
        else if(sumNow < M && i == n-1)
        {
            sum++;
        }
    }
    printf("%lld\n", sum);
    return 0;
}