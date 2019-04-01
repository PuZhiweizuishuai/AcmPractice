#include <stdio.h>
#define MAX 1005

/**
 * 分量ID 
 * */
int ID[MAX];

/**
 * 分量数量，冗余关系的数目
*/
int count;

/**
 * 初始化
*/
void init(int n)
{
    count = n;
    int i;
    // 因为点从 1 开始，所以 n 值加 1
    for (i = 0; i < (n + 1); i++)
    {
        ID[i] = -1;
    }
}

/**
 * 查找跟节点
*/
int find(int p)
{
    while (-1 != ID[p])
    {
        p = ID[p];
    }
    return p;
}

/**
 * 连接
*/
void unions(int pRoot, int qRoot)
{
    if (qRoot == pRoot)
    {
        return;
    }
    ID[pRoot] = qRoot;
    count--;
}

int connected(int pRoot, int qRoot)
{
    if (pRoot == qRoot)
        return 0;
    else
        return 1;
}

int main(void)
{
    int n, m, p, q;
    int num;
    scanf("%d%d", &n, &m);
    init(m);
    num = n;
    while (n--)
    {
        scanf("%d%d", &p, &q);
        int pRoot = find(p);
        int qRoot = find(q);
        if (connected(pRoot, qRoot) == 1)
            unions(pRoot, qRoot);
    }
    printf("%d\n", count);
    return 0;
}
