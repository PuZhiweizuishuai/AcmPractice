
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;
const int maxn = 35;
double mp[maxn][maxn];
int f[maxn];
typedef struct
{
    int x;
    int y;
    int z;
} ZB;
ZB a[maxn];
typedef struct
{
    int x;
    int y;
    double w;
} QQ;
QQ b[maxn];
bool cmp(QQ a, QQ b)
{
    return a.w < b.w;
}
int findx(int x)
{
    int r = x;
    while (r != f[r])
        r = f[r];
    return r;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            f[i] = i;
        }
        memset(mp, 0, sizeof(mp)); //初始化
        double len;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                len = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].z - a[j].z) * (a[i].z - a[j].z));
                mp[i][j] = mp[j][i] = len; //构造邻接矩阵
            }
        }
        int q = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (j > i)
                {
                    q++;
                    b[q].x = i;
                    b[q].y = j;
                    b[q].w = mp[i][j];
                }
            }
        sort(b + 1, b + q + 1, cmp);
        int p = 0;
        double ans = 0;
        for (int i = 1; i <= q; i++)
        {
            if (findx(b[i].x) != findx(b[i].y))
            {
                ans += b[i].w;
                f[findx(b[i].x)] = b[i].y;
                p++;
                if (p == n - 1)
                    break;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
