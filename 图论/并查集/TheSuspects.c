#include <stdio.h>
#define MAX 30005

int friend[MAX];
int size[MAX];

void UF(int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        friend[i] = i;
        size[i] = 1;
    }
}

int find(int p)
{
    while (p != friend[p])
    {
        p = friend[p];
    }
    return p;
}

int connected(int p, int q)
{
    if (find(p) == find(q))
        return 1;
    return 0;
}

void Unions(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j)
        return;

    if (size[i] < size[j])
    {
        friend[i] = j;
        size[j] += size[i];
    }
    else
    {
        friend[j] = i;
        size[i] += size[j];
    }
}

int main(void)
{
    int n, m, k, ktemp, p, ptemp, num = 1, i;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        num = 1;
        if (n == 0 && m == 0)
            break;
        UF(n);
        while (m--)
        {
            scanf("%d", &k);
            ktemp = k;
            while (k--)
            {
                if (k == ktemp - 1)
                {
                    scanf("%d", &p);
                    ptemp = p;
                    continue;
                }
                else
                {
                    scanf("%d", &p);
                    if (connected(ptemp, p) == 1)
                        continue;
                    Unions(ptemp, p);
                    ptemp = p;
                }
            }
        }
        /*for(i = 0; i <= n; i++)
        {
            printf("size[%d]=%d friend[%d] = %d  find = %d\n",i,size[friend[i]],i,friend[i], find(i));
        }*/


        printf("%d\n", size[friend[0]]);
    }
    return 0;
}
