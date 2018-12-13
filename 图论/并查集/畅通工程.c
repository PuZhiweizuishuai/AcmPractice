#include <stdio.h>
#define MAX 1005
/**
 * 某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
 * 省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，
 * 只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
 * 
 * 输入：
 * 测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，
 * 分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，
 * 每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。
 * 为简单起见，城镇从1到N编号。
 * 注意:两个城市之间可以有多条道路相通,也就是说
 * 3 3
 * 1 2
 * 1 2
 * 2 1
 * 这种输入也是合法的
 * 当N为0时，输入结束，该用例不被处理。
 * 
 * 输出：
 * 对每个测试用例，在1行里输出最少还需要建设的道路数目。   
 * 
*/

/**
 * 城市链接数组，触点
*/
int city[MAX];
/**
 * 各个根节点所对应的分量大小，权值
*/
int size[MAX];
/**
 * 修建道路的数目
*/
int count;

/**
 * 初始化
*/
void UF(int n)
{
    int i;
    // 道路数目为 城市数 - 1
    count = n - 1;
    // 初始化节点和权值
    for (i = 0; i <= n; i++)
        city[i] = i;
    for (i = 0; i <= n; i++)
        size[i] = -1;
}

/**
 * 查找分量标识符
*/
int find(int p)
{
    // 跟随链接找到根节点
    while (p != city[p])
    {
        p = city[p];
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
    // 将小树的根节点连接到大树的根节点
    if (size[i] < size[j])
    {
        city[i] = j;
        size[j] += size[i];
    }
    else
    {
        city[j] = i;
        size[i] += size[j];
    }
    count--;
}

int main(void)
{
    int n, m, p, q, i, t = -1;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        scanf("%d", &m);
        UF(n);
        while (m--)
        {
            scanf("%d%d", &p, &q);
            if (connected(p, q))
                continue;
            unions(p, q);
        }
        if (count < 0)
            printf("0\n");
        else
            printf("%d\n", count);
    }
    return 0;
}