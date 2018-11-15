#include <stdio.h>
#define MaxN 15
#define MaxM 15
/**
 * A为一个方阵，则Tr A表示A的迹（就是主对角线上各项的和），现要求Tr(A^k)%9973。
 * 输入：
 * 数据的第一行是一个T，表示有T组数据。
 * 每组数据的第一行有n(2 <= n <= 10)和k(2 <= k < 10^9)两个数据。
 * 接下来有n行，每行有n个数据，每个数据的范围是[0,9]，表示方阵A的内容。
 * 对应每组数据，输出Tr(A^k)%9973。
*/
typedef struct
{
    int n, m;
    int mat[MaxN][MaxN];
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

Matrix Multiply(const Matrix a, const Matrix b, const int n)
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

Matrix Pow(const Matrix a, int b, const int n)
{
    if (b == 0)
        return One(a.n);
    Matrix tmp = Pow(a, b / 2, n);
    tmp = Multiply(tmp, tmp, n);
    if (b % 2 == 1)
        tmp = Multiply(a, tmp, n);
    return tmp;
}

int TrA(Matrix a, const int n)
{
    int sum = 0, i;
    for (i = 0; i < a.n; i++)
        sum = (sum + a.mat[i][i]) % n;
    return sum;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    int n, k, i, j;
    Matrix x;
    while (T--)
    {
        scanf("%d%d", &n, &k);
        x.n = x.m = n;
        for (i = 0; i < x.n; i++)
            for (j = 0; j < x.m; j++)
                scanf("%d", &x.mat[i][j]);
        printf("%d\n", TrA(Pow(x, k, 9973), 9973));
    }
    return 0;
}