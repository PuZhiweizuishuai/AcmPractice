/**
 * MAXN 矩阵的最大行数
 * MAXM 矩阵的最大列数
*/
#define MAXN 10
#define MAXM 10

/**
 * n    矩阵的行数
 * m    矩阵的列数
 * mat  存储矩阵的二维数组，使用静态大小
 *      mat[i][j]表示矩阵第i行第j列元素
*/
typedef struct
{
    int n, m;
    int mat[MAXN][MAXM];
} Matrix;

/**
 * 单位矩阵
 * @param n 单位矩阵的阶数
*/
Matrix One(const int n)
{
    int i, j;
    Matrix a;
    a.n = a.m = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i == j)
                a.mat[i][j] = 1;
            else
                a.mat[i][j] = 0;
    return a;
}

/**
 * 矩阵乘法
 * 主要保证a.m等于b.n
 * 
 * @param a 矩阵A
 * @param b 矩阵B
 * @return 矩阵A与矩阵B的乘积
*/
Matrix Multi(const Matrix a, const Matrix b, const int n)
{
    Matrix c;
    int i, j, k;
    c.n = a.n;
    c.m = b.m;
    for (i = 1; i <= a.n; i++)
        for (j = 1; j <= b.m; j++)
        {
            c.mat[i][j] = 0;
            for (k = 1; k <= a.m; k++)
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % n;
        }
    return c;
}

/**
 * 矩阵快速幂
 * 
 * @param a 模取幂运算的底数，请确保矩阵A的为n*n的方阵
 * @param b 模取幂运算的指数
 * @param n 模取幂运算的基数
*/
Matrix Pow(const Matrix a, const int b, const int n)
{
    if (!b)
        return One(a.n);
    Matrix tmp = Pow(a, b >> 1, n);
    tmp = Multi(tmp, tmp, n);
    if (b & 1)
        tmp = Multi(tmp, a, n);
    return tmp;
}