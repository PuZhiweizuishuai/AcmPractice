#include <stdio.h>
#include <string.h>

#define N 100
#define MaxN 15
#define MaxM 15

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
                c.mat[i][j] = ((c.mat[i][j] % n) + (a.mat[i][k] % n) * (b.mat[k][j] % n) % n) % n;
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

Long main(void)
{
    Long countA[127], countB[127], T, i, j, k;
    Matrix A = {.n = 2, .m = 2, .mat = {{1, 1}, {1, 0}}};
    char a[N], b[N], ch;
    scanf("%d", &T);
    while (T--)
    {
        memset(countA, 0, sizeof(countA));
        memset(countB, 0, sizeof(countB));
        scanf("%s%s%d", a, b, &k);
        for (i = 0; a[i] != '\0'; i++)
            countA[a[i]]++;
        for (i = 0; b[i] != '\0'; i++)
            countB[b[i]]++;

        for (ch = 'a'; ch <= 'z'; ch++)
        {
            if (k == 0)
            {
                printf("%c:%lld\n", ch, countA[ch]);
            }
            else
            {
                Matrix x = {.n = 2, .m = 1, .mat = {{countB[ch]}, {countA[ch]}}};
                Matrix B = Pow(A, k - 1, __INT_MAX__);
                Matrix ans = Multiply(B, x, __INT_MAX__);
                printf("%c:%d\n", ch, ans.mat[0][0]);
            }
        }
        printf("\n");
    }
    return 0;
}