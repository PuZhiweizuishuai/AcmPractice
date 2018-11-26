#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100
#define MaxN 15
#define MaxM 15
/**
 * Xiao Ming found the compute time of gcd(fibn,fibn+1)gcd(fibn,fibn+1) 
 * is the most when he learnt the gcd, and the result of it is always fib1fib1 but he is not satisfied with the simple compute result. 
 * He wants to know what gcd(1+Sn,1+Sm)gcd(1+Sn,1+Sm) equals. 
 * And gcd is greatest common divisor, fib1=1,fib2=1，fib2=1,fibn=fibn−1+fibn−2fibn=fibn−1+fibn−2(n≥3)
 * Sn=∑ni=1fibiSn=∑i=1nfibi 
 * 
 * 输入
 *
 * The first line is an positive integer T. (1 ≤ T ≤ 10^3) 
 * indicates the number of test cases. In the next T lines, 
 * there are three positive integer n, m, p(1 ≤ n, m, p ≤ 10^9) at each line.
 * 输出
 *
 * In each test case, output the compute result of gcd(1+Sn,1+Sm)mod pgcd(1+Sn,1+Sm)mod p at one line.  
 * 
 * 
 * 通过查找资料可知，斐波那契数列前n项和等于
 * S(n) = F(n+2)-1
*/
typedef long long int Long;
typedef struct
{
    Long n, m;
    Long mat[MaxN][MaxN];
} Matrix;

Matrix One(const Long n)
{
    Matrix a;
    Long i, j;
    a.n = a.m = n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i == j)
                a.mat[i][j] = 1;
            else
                a.mat[i][j] = 0;
        }
    return a;
}

Matrix Multiply(const Matrix a, const Matrix b, const Long n)
{
    Matrix c;
    Long i, j, k;
    c.n = a.n;
    c.m = b.m;
    for (i = 0; i < a.n; i++)
        for (j = 0; j < b.m; j++)
        {
            c.mat[i][j] = 0;
            for (k = 0; k < a.m; k++)
                c.mat[i][j] = ((c.mat[i][j] % n) + (a.mat[i][k] % n) * (b.mat[k][j] % n)) % n;
        }
    return c;
}

Matrix Pow(const Matrix a, Long b, const Long n)
{
    if (b == 0)
        return One(a.n);
    Matrix tmp = Pow(a, b / 2, n);
    tmp = Multiply(tmp, tmp, n);
    if (b % 2 == 1)
        tmp = Multiply(a, tmp, n);
    return tmp;
}

Long GCD(Long p, Long q)
{
    if (q == 0)
        return p;
    Long r = p % q;
    return GCD(q, r);
}

Long FibonacciSum(Long n, Long mod)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    //n = n + 2;
    Matrix A = {.n = 2, .m = 2, .mat = {{1, 1}, {1, 0}}};
    Matrix x = {.n = 2, .m = 1, .mat = {{1}, {1}}};
    Matrix B = Pow(A, n - 2, mod);
    Matrix ans = Multiply(B, x, mod);
    return ans.mat[0][0];
}

int main(void)
{
    int T;
    Long n, m, p, ans, k;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &m, &p);
        k = GCD(n+2,m+2);
        ans = FibonacciSum(k,p) % p;
        //ans = GCD(1 + FibonacciSum(n,p), 1 + FibonacciSum(m,p)) % p;
        // 注意小于二的特殊情况
        if(k > 2)
            printf("%lld\n", ans);
        else
            printf("1\n");
    }
    return 0;
}

