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

Matrix MultiWithNum(const Matrix a, const int k, const int n)
{
    Matrix b;
    int i, j;
    for (i = 1; i <= a.n; i++)
        for (j = 1; j <= a.m; j++)
            b.mat[i][j] = (a.mat[i][j] % n) * (k % n) % n;
    return b;
}