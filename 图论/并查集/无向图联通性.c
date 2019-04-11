#include <stdio.h>
#define MAX 4000010
#define N 998244353
int ID[MAX];

void init(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        ID[i] = -1;
    }
}

int find(int p)
{
    while (ID[p] != -1)
    {
        p = ID[p];
    }
    return p;
}

void unions(int p, int q)
{
    if (p == q)
        return;
    ID[p] = q;
}

int connected(int p, int q)
{
    if (p == q)
        return 1;
    else
        return 0;
}

int Pow(int a, int b)
{
    int t;
    b = b-1;
    if(b == -1)
        return 1;
    for (t = 1; b; b >>= 1)
    {
        if (b & 1)
            t = t * a;
        a = a * a;
    }
    return a;
}




int main(void)
{
    int i, j;
    int n, m, op, u, v;
    int number[MAX], answer = 0;
    scanf("%d%d", &n, &m);
    init(n);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &op, &u, &v);
        int q = find(u);
        int p = find(v);
        if (op == 0)
        {
            if (connected(p, q))
            {
                continue;
            }
            else
            {
                unions(p, q);
            }
        }
        else
        {
            if (connected(p, q))
            {
                answer = ((answer << 1) % 998244353 + 1) % 998244353;
            }
            else
            {
                answer = ((answer << 1) % 998244353);
            }
        }
    }
    printf("%d\n",answer);
    
    
    return 0;
}