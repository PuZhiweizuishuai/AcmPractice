#include<stdio.h>
#define MAX 1005

int friend[MAX];
int size[MAX];
int count;

void UF(int m)
{
    int i;
    count = m;
    for(i = 0; i <= m; i++)
    {
        friend[i] = i;
        size[i] = 1;
    }
        
}

int find(int p)
{
    while(p != friend[p])
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
    if(i == j)
        return ;
    
    if(size[i] < size[j])
    {
        friend[i] = j;
        size[j] += size[i];
    }
    else
    {
        friend[j] = i;
        size[i] += size[j];
    }
    count--;
}



int main(void)
{
    int T,n,m,p,q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        UF(m);
        while(n--)
        {
            scanf("%d%d",&p,&q);
            if(connected(p,q))
                continue;
            Unions(p,q);
        }
        printf("%d\n",count);
    }
    return 0;
}
