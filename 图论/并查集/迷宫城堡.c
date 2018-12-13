#include <stdio.h>
#define MAX 100005
/**
 * HDU1272 并查集模板题
 * 注意图是否连通，如果不连通则也要输出No
 * 我刚开始在这卡了许久
*/

/**
 * 节点
*/
int id[MAX];
/**
 * 标记出现过的数
*/
int mark[MAX];
/**
 * 记录数的深度
*/
int size[MAX];
/**
 * 判断
*/
int flag;

/**
 * 初始化
*/
void UF(int n)
{
    int i;  
    for (i = 0; i <= n; i++)
    {
        id[i] = i;
        size[i] = -1;
        mark[i] = 0;
    }
        
}

/**
 * 查找分量标识符
*/
int find(int p)
{
    while (p != id[p])
    {
        p = id[p];
    }
    return p;
}

/**
 * 如果 p 和 q 在同一节点中返回 1
*/
int connected(int p, int q)
{
    if (find(p) == find(q))
        return 1;
    return 0;
}

/**
 * 在 p 和 q 之间添加一条连接
*/
void unions(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j)
        return;
    if (size[i] < size[j])
    {
        id[i] = j;
        size[j] += size[i];
    }
    else
    {
        id[j] = i;
        size[i] += size[j];
    }
}

/**
 * 判断图是否连通
*/
void IsUnicom()
{
    int i, count = 0;
    for(i = 0; i < MAX; i++)
    {
        if(mark[i] && id[i] == i)
            count++;
    }
    // 如果父节点大于 1，则图没有连通，也要输出 No
    if(count > 1)
        flag = 1;
}


int main(void)
{
    int p, q, i;
    while (1)
    {
        UF(100000);
        flag = 0;
        while (1)
        {
            scanf("%d%d", &p, &q);
            if (p == 0 && q == 0)
                break;
            if (p == -1 && q == -1)
                return 0;
            // 将出现过的数标记为 1
            mark[p] = 1;
            mark[q] = 1;    
            // 如果两个节点已连接， flag 标记为 1
            if (connected(p, q))
            {
                flag = 1;
                continue;
            }
            unions(p, q);
        }
        // 判断连通
        IsUnicom();
        if (flag == 1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
