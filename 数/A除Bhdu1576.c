#include <stdio.h>
/**
 * hdu 1576 A/B
 * 思路
 * 求(A/B)%9973
 * 设 A/B = x;
 * 则 A = Bx
 * 而 n = A % 9973
 * n = A - (A / 9973) * 9973
 * n = Bx - (A / 9973) * 9973
 * 令 A / 9973 = y
 * n = Bx - 9973y
 * 由题知gcd(B,9973) = 1
 * 则
 * n * gcd(B,9973) =  Bx + (-9973y)
 * 因此求出 x 的值即可得到最终结果
 * 而该式形如 ax + by = gcd(a,b)
 * 则由扩展欧几里得算法可解得 x
*/

int MOD(int a, int b)
{
    return (a % b + b) % b;
}

/**
 * 欧几里得算法非递归实现
*/
int EXGCD(int a, int b, int num)
{
    int x,y;
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int m,m1,n,n1,c,d,q,r,t;
    m1 = n = 1;
    m = n1 = 0;
    c = a;
    d = b;
    q = c / d;
    r = c % d;
    while(r)
    {
        c = d;
        d = r;
        t = m1;
        m1 = m;
        m = t - q * m;
        t = n1;
        n1 = n;
        b = t - q * b;
        q = c / d;
        r = c % d;
    }
    x = m;
    y = n;
    if(x < 0)
        x += 9973;
    
    return x * num;
}

int main()
{
    int x,n,B,T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &B);
        x = EXGCD(B,9973,n);
        
        printf("%d\n",x%9973);
    }
    return 0;
}