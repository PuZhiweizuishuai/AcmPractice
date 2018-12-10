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
 * 矩阵相加法则，两个矩阵对应位置的数相加并保存到相应的位置。
 * 请保证两个矩阵的行数和列数都相等。
 * 
 * @param a 矩阵A
 * @param b 矩阵B
 * @param 两个矩阵相加后的结果
*/
Matrix Add(const Matrix a, const Matrix b, const int n)
{
    Matrix c;
    int i, j;
    c.n = a.n;
    c.m = a.m;
    for (i = 1; i <= a.n; i++)
        for (j = 1; j <= a.m; j++)
            c.mat[i][j] = (a.mat[i][j] % n + b.mat[i][j] % n) % n;
    return c;
}
