#include <bits/stdc++.h>
/*
题意：
两人去看电影 两人有一些喜欢的电影 给你两人喜欢电影放映的时间 两人不能连着看一个人不喜欢的电影2场 问你最多能看多少场电影
分析：
贪心就行了 
*/
using namespace std;
const int maxn = 1e6 + 5;
struct node
{
    int num;
    int t;
} a[2 * maxn];

int cmp(node a, node b)
{
    if (a.num == b.num)
        return a.t < b.t;
    return a.num < b.num;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].num);
        a[i].t = 0;
    }
    scanf("%d", &m);
    for (int i = n + 1; i <= n + m; i++)
    {
        scanf("%d", &a[i].num);
        a[i].t = 1;
    }
    a[0].num = 0;
    a[0].t = -1;
    sort(a, a + n + m + 1, cmp);

    int ans = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (a[i].t != a[i - 1].t)
        {
            ans++;
        }
        else
        {
            if (a[i + 1].num == a[i].num)
            {
                ans++;
            }
        }
        if (a[i].num == a[i + 1].num)
        {
            a[i + 1].t = -1;
            i++;
        }
    }
    printf("%d\n", ans);
    return 0;
}