#include <cstdio>
#include <vector>
#include <algorithm>

struct Node
{
    int start, end, num;
    Node(int s, int e, int h) : start(s), end(e), num(h) {}
};

bool cmp(const Node &a, const Node &b)
{
    return a.end < b.end;
}

std::vector<Node> nodes;
// n: 区间数量，m：要求数量， ans：最少需要的多少棵树
int n, m, ans = 0;
bool flag[50005]; //检测编号为i的单元是否已经种上了树
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0, s, e, h; i < m; i++)
    {
        scanf("%d %d %d", &s, &e, &h);
        nodes.push_back(Node(s, e, h));
    }
    sort(nodes.begin(), nodes.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        int tmp = 0; //表示当前已经种了多少棵树，判断tmp与需要种的数量是否相等
        for (int j = nodes[i].start; j <= nodes[i].end; j++)
        {
            if (flag[j])
                tmp++;
            if (tmp == nodes[i].num)
                break;
        }
        if (tmp < nodes[i].num)
        {
            for (int j = nodes[i].end; j >= nodes[i].start; j--)
            {
                if (!flag[j])
                {
                    flag[j] = true;
                    tmp++;
                    ans++;
                    if (tmp == nodes[i].num)
                    {
                        break;
                    }
                }
            }
        }
    }
    printf("%d", ans);
}