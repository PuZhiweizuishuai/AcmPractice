#include<stdio.h>
#include<math.h>
#define N_MAX 100000
#define False 0
#define True 1

int Max(const int a, const int b);

void IsPrime(const int l, const int r, const int n);

int main(void)
{
    IsPrime(100, 200, test);
  
    return 0;
}

/**
 * l 到 r 为区间
 * n 为 l 到 r 区间的数
*/
void IsPrime(const int l, const int r, const int n)
{
    const int N = sqrt(r);
    int isPrime[N], count = 0;
    int isPrimeLR[r-l];
    int i, j, begin;
    for(i = 0; i < Max(N, r-l); i++)
    {
        if(i < N)
            isPrime[i] = True;
        if(i < r-l)
            isPrimeLR[i] = True;
    }
        
    isPrime[0] = isPrime[1] = False;
    for(i = 0; i < N; i++)
    {
        if(isPrime[i])
        {
            // 筛 0 到 sqrt(l) 的素数
            for(j = 2 * i; j < N; j += i)
                isPrime[j] = False;    
                
            // 筛 r 到 l
            // begin 寻找大于 r 最小的素数倍数
            begin = Max(2, (l + i - 1) / i) * i;
            for(j = begin; j < r; j += i)
                isPrimeLR[j-l] = False;
        }
    }
    printf("%d = %d\n",n, isPrimeLR[n-l]);
}

int Max(const int a, const int b)
{
    if(a > b)
        return a;
    else
        return b;
}
