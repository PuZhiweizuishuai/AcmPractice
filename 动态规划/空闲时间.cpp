#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 10010
using namespace std;
int f[M], n, k;
bool flag[M];
struct node
{
    int begin, t;
};
node a[M];
bool cmp(const node &x, const node &y)
{
    return x.begin < y.begin;
}
int erfen(int l, int r, int v)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m].begin < v)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &a[i].begin, &a[i].t);
        flag[a[i].begin] = true;
    }
    for(int i = 1; i <= k; i++)
        printf("%d\n",a[i].begin);
    printf("\n");
    sort(a + 1, a + k + 1, cmp);
    for(int i = 1; i <= k; i++)
        printf("%d\n",a[i].begin);
    for (int i = n; i >= 1; i--)
        if (flag[i])
        {
            int t = erfen(1, k, i);
            for (int j = t; a[j].begin == i; j++)
                f[i] = max(f[i], f[i + a[j].t]);
        }
        else
            f[i] = f[i + 1] + 1;
    printf("%d", f[1]);
    return 0;
}