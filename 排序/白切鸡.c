#include<stdio.h>
#include<stdlib.h>
#define MAX 3000
/**
 * 输入：
 * 第一行输入一个整数T，代表T组数据 
 * 加下来第一行输入两个整数N,M，N表示开始参加斗鸡比赛的鸡的个数，M表示接下来的操作数量 N.M∈[1,1000]
 * 接下来一行输入N个整数表示每只鸡的战斗力 
 * 接下来M行，每行两个整数a,b，当a为0时表示，查询第b位置上的鸡的战斗力，否则表示一只战斗力为b的鸡加入来斗鸡比赛 
 * 
 * 
 * 输出：
 * 每次a为0是输出一个整数占一行，表示查询到的第b位置上的鸡的战斗力。（注意：排名是从1开始的） 
*/

void Sort(int A[], int n)
{
    int h = 0;
    int i,j,get;
    while (h <= n)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (i = h; i < n; i++)
        {
            j = i - h;
            get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h - 1) / 3;
    }
}

int main(void)
{
    int T,N,M, a, b;
    int zhandouli[MAX];
    int i, j = 0;

    scanf("%d",&T);
    while(T--)
    {
        for(i = 0; i < MAX; i++)
            zhandouli[i] = 0;
        j = 0;
        scanf("%d%d",&N, &M);
        for(i = 0; i < N; i++)
            scanf("%d",&zhandouli[i]);
        Sort(zhandouli, N);
        while(M--)
        {
            scanf("%d%d",&a,&b);
            if(a == 0)
                printf("%d\n",zhandouli[b-1]);
            else
            {
                // 添加排序的数
                zhandouli[N++] = b;
                // 此处可以改为插入排序，因为此时数组接近有序，而插入排序对接近有序的数组排序非常快
                Sort(zhandouli,N);
            }
        }
    }

    return 0;
}