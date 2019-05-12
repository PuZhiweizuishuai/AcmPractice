#include <stdio.h>
#define N 1000100
long int isPrime[N];
long int sum = 0;
void TheSieveOfEratosthenes()
{
    long int i, j;

    for (i = 0; i < N; i++)
        isPrime[i] = 1;

    isPrime[0] = isPrime[1] = 0;

    for (i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            sum++;
            isPrime[i] = sum;
            for (j = i + i; j < N; j = j + i)
                isPrime[j] = 0;
        }
    }
}

long int LPF(long int n)
{
    long int i, max = 0;
    for (i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
        }
        if (i > max)
            max = i;
    }
    return isPrime[max];
}

int main(void)
{
    TheSieveOfEratosthenes();
    long int i, n;
    while (scanf("%ld", &n) != EOF)
    {
        printf("%ld\n", LPF(n));
    }
    return 0;
}
