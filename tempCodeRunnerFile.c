#include <stdio.h>
#include <string.h>
#define MAX 100000000

int isPrime[MAX];

void Prime() 
{
    long long int i, j;
    for(i = 0; i < MAX; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(i = 2; i < MAX; i++)
    {
        if(isPrime[i])
        {
            for(j = i + i; j < MAX; j = j + i)
                isPrime[j] = 0;
        }
    }
}

int fact(long long int n)
{
    long long int i;
    int flag = 1;
    for (i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            if(isPrime[i] == 0)
                return 0;
            n = n / i;
        }
    }
    return flag;
}

int main(void)
{
    Prime();
    long long int T,i;
    while (scanf("%lld", &T) != EOF)
    {
        if(T == 0)
            break;
        for(i = T+1; ;i++)
            if(isPrime[i] == 1 && fact(i) == 1)
            {
                printf("%lld\n", i);
                break;
            }
    }
    return 0;
}