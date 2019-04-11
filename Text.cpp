#include <cstdio>
#include <algorithm>
#include <iostream>
struct node
{
    int u, v, w;
} e[50050];
int f[50050];
void init(void)
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
}
int fd(int x)
{
    return f[x] == x ? x : fd[x] = fd(f[x]);
}
int uion(int x, int y)
{
    int fa = fd(x), fb = fd(y);
    if (fa != fb)
        f[fa] = fb;
}
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int kuskal(void)
{
    sort(e, e + n);
    int ans = 0;
    for (int i = 0; i < m; i++) //m为边数
    {
        int u, v, fu, fv;
        u = e[i].u;
        v = e[i].v;
        fu = fd(u), fv = fd(v);
        if (fu != fv)
        {
            ans += e[i].w;
            uion(u, v);
        }
    }
    return ans;
}