#include <stdio.h>
#define MAX 1005
/**
 * 现在这里有一篇作文,有n句描述人物关系的句子,描述了n个人的关系每条句子的定义是这样的 X  Y  
 * 它的意思是:X认识Y  Y也认识X 现在要你求出文中冗余关系的数目.
 * 注意:  假如A认识B,B认识C,则A也认识C 冗余关系的定义是指  :  即使没有这条关系,原图的所有关系照样成立.
 * 
 * 第一行,两个整数,表示句子数量(n)，表示人数(m)。接下来n行,每行两个数,意义在描述里已经说了.  
 * 
 * 一个整数,表示冗余关系的数目.
*/

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
void UF(int n)
{
    count = n;
    int i;
    // 因为点从 1 开始，所以 n 值加 1
    for (i = 0; i < (n + 1); i++)
        ID[i] = i;
}

int find(int p)
{
    while (p != ID[p])
    {
        p = ID[p];
    }
    return p;
}

void unions(int p, int q)
{
    int pRoot = find(p);
    int qRoot = find(q);
    if (qRoot == pRoot)
    {
        return;
    }
    ID[pRoot] = qRoot;
    count--;
}

int connected(int p, int q)
{
    if(find(p) == find(q))
        return 1;
    else
        return 0;
}

int main(void)
{
    int n, m,p,q;
    
    scanf("%d%d",&n,&m);
    UF(m);
    while(n--)
    {
        scanf("%d%d",&p,&q);
        if(connected(p,q) == 1)
            continue;
        unions(p,q);
    }
    printf("%d",count);
    return 0;
}