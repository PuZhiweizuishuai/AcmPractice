#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100005

int mark[MAX];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int fun(long long int n)
{
    long long int i;
    for(i = 0; i < n; i++)
    {
        if(mark[i] == 1)
            return 0;
    }
    return 1;
}


int judge(long long int a[], long long int n, long long int sum)
{
    memset(mark,1,sizeof(mark));
    if (sum % 2 != 0)
        return 0;
    long long int i,b = sum / 2;
    long long int left = 0,right = 0;
    qsort(a, n, sizeof(a[0]), cmp);
    
    for(i = n-1; i >= 0; i--)
    {
        if(right == b)
            break;
        if(right > b)
            continue;
        mark[i] = 0;
        right += a[i];
    }
    if(right != b)
        return 0;
    for(i=n-1;i>=0;i--)
    {
        if(left == b)
            break;
        if(left > b)
            continue;
        if(mark[i])
        {
            mark[i] = 0;
            left += a[i];
        }
    }
    if(right == left && fun(n))
        return 1;
    
    return 0;
}

int main(void)
{
    long long int i;
    long long int n, a[MAX], sum = 0;
    while (scanf("%lld", &n) != EOF)
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        if(judge(a,n,sum)) 
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
    }

    return 0;
}