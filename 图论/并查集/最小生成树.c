#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int u;
    int v;
    int w;
} NODE;

int Comp(const void *p1, const void *p2)
{
    NODE *c = (NODE *)p1;
    NODE *d = (NODE *)p2;
    if (c->w != d->w)
        return c->w - d->w;
    else
        return c->w - d->w;
}

int ID[200005];
int size[200005];
NODE G[500005];

void init(int n)
{
    int i;
    for (i = 0; i < (n + 1); i++)
    {
        ID[i] = -1;
        size[i] = -1;
    }
}

int find(int p)
{
    while (-1 != ID[p])
    {
        p = ID[p];
    }
    return p;
}

void unions(int pRoot, int qRoot)
{
    if (qRoot == pRoot)
    {
        return;
    }
    if (size[pRoot] < size[qRoot])
    {
        ID[pRoot] = qRoot;
        size[qRoot] += size[pRoot];
    }
    else
    {
        ID[qRoot] = pRoot;
        size[pRoot] += size[qRoot];
    }
}

int connected(int pRoot, int qRoot)
{
    if (pRoot == qRoot)
        return 1;
    else
        return 0;
}

int Kruskal(int n, int m)
{
    int i;
    qsort(G, m, sizeof(G[0]), Comp);
    int sum = 0, total = 0;
    for (i = 0; i < m; i++)
    {
        int p = find(G[i].u);
        int q = find(G[i].v);
        if (connected(p, q))
        {
            continue;
        }
        else
        {
            unions(p, q);
            total++;
            sum += G[i].w;
            if (total == n - 1)
                break;
        }
    }
    return sum;
}

int main(void)
{
    int i, j;
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
    }
    printf("%d\n", Kruskal(n, m));
    return 0;
}