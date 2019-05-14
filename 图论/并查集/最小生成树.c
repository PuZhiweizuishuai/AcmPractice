#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    long long int u;
    long long int v;
    long long int w;
} NODE;

int Comp(const void *p1, const void *p2)
{
    NODE *c = (NODE *)p1;
    NODE *d = (NODE *)p2;

    return c->w - d->w;
}

long long int ID[200005];
long long int size[200005];
NODE G[500005];

void init(long long int n)
{
    long long int i;
    for (i = 0; i < (n + 1); i++)
    {
        ID[i] = -1;
        size[i] = -1;
    }
}

long long int find(long long int p)
{
    if(ID[p] == -1)
        return p;
    return ID[p] = find(ID[p]);
}

void unions(long long int pRoot,long long int qRoot)
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

int connected(long long int pRoot, long long int qRoot)
{
    if (pRoot == qRoot)
        return 1;
    else
        return 0;
}

long long int Kruskal(long long int n, long long int m)
{
    long long int i;
    qsort(G, m, sizeof(G[0]), Comp);
    long long int sum = 0, total = 0;
    for (i = 0; i < m; i++)
    {
        long long int p = find(G[i].u);
        long long int q = find(G[i].v);
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
    long long int i, j;
    long long int n, m;
    scanf("%lld%lld", &n, &m);
    init(n);
    for (i = 0; i < m; i++)
    {
        scanf("%lld%lld%lld", &G[i].u, &G[i].v, &G[i].w);
    }
    printf("%lld\n", Kruskal(n, m));
    return 0;
}