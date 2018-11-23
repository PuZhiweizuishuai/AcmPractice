#include <stdio.h>
#define MaxN 15
#define MaxM 15
/**
 * f(0) = 0 
 * f(1) = 1
 * f(2) = 3
 * f(n) = f(n-1) + 3 * f(n - 2) + 4 * f(n - 3)
 * 递推式f(n)的第 i 项，因为结果可能会很大，只需要输出结果对1000000007(10^9+7)取余数即可。
 * 
 * 构建矩阵a
 * 1    3    4
 * 1    0    0
 * 0    1    0
 * b
 * 3
 * 1
 * 0
 * 求a矩阵的n次幂乘b矩阵所得结果的首项即是结果
*/
typedef struct
{
    int n, m;
    long long int mat[MaxN][MaxN];
} Matrix;

Matrix One(const int n)
{
    Matrix a;
    int i, j;
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

Matrix Multiply(const Matrix a, const Matrix b, const long long int n)
{
    Matrix c;
    int i, j, k;
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

Matrix Pow(const Matrix a, int b, const long long int n)
{
    if (b == 0)
        return One(a.n);
    Matrix tmp = Pow(a, b / 2, n);
    tmp = Multiply(tmp, tmp, n);
    if (b % 2 == 1)
        tmp = Multiply(a, tmp, n);
    return tmp;
}




int main()
{
    Matrix m,K;
    m.n = m.m = 3;
    K.n = 3;
    K.m = 1;
    int i,j;
    m.mat[0][0] = 1;m.mat[0][1] = 3;m.mat[0][2] = 4;
    m.mat[1][0] = 1;m.mat[1][1] = 0;m.mat[1][2] = 0;
    m.mat[2][0] = 0;m.mat[2][1] = 1;m.mat[2][2] = 0;
    K.mat[0][0] = 3;
    K.mat[1][0] = 1;
    K.mat[2][0] = 0;
    long long int number;
    while(scanf("%lld",&number) != EOF)
    {
        if(number == 0)
            printf("0\n");
        else if(number == 1)
            printf("1\n");
        else if(number == 2)
            printf("3\n");
        else
        {
            Matrix t = Pow(m,number-2,1000000007);  
            Matrix temp = Multiply(t,K,1000000007);
            printf("%lld\n",temp.mat[0][0]);
        }
    }
    return 0;
}