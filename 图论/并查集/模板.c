#include <stdio.h>

int s[10005]; //大小根据题目而定

void Initialize(int *s, int n)
{
    int i;
    for (i = 0; i < n; i++)
        s[i] = -1;
}

void Union(int *s, int root1, int root2)
{
    s[root2] = root1;
}

int Find(int *s, int x)
{
    if (s[x] == -1)
        return x;
    else
        return Find(s, s[x]);
}

int main(int argc, char **argv)
{
    int i;
    int n, m;
    int a, b, c;
    int r1, r2;
    // 输入元素的个数与关系的个数
    scanf("%d%d", &n, &m);
    // 如果编号从1开始则换成n+1
    Initialize(s, n);
    // 开始添加关系
    for (i = 0; i < m; i++)
    {
        // 输入添加的关系a~b
        scanf("%d%d", &a, &b);
        // 查找两个元素所在的等价类的根
        r1 = Find(s, a);
        r2 = Find(s, b);
        // 判断是否存在等价关系
        // 避免添加冗余关系
        if (r1 != r2)
        {
            Union(s, r1, r2);
        }
        else
        {
            // 如果需要统计冗余关系则在这里统计
        }
    }
    // 开始统计等价类/连通分量/独立团的个数
    // 如果编号从1开始则换成for(i=1;i<=n;i++)
    for (c = 0, i = 0; i < n; i++)
    {
        if (s[i] == -1)
        {
            c++;
        }
    }
}