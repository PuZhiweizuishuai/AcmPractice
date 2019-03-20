#include <stdio.h>
#include <stdlib.h>
#define N 1050

int Greedy(int n, int s[], int f[], int b[])
{
    int sum = 1;
    // 默认将第一个活动先安排
    b[0] = 1;
    // 记录最近一次加入b中的活动
    int j = 0; 

    // 依次检查活动i是否与当前已选择的活动相容
    for (int i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            b[i] = 1;
            j = i;
            sum ++;
        }
        else
            b[i] = 0;
    }
    return sum;
}

int main(void)
{
    // 存储活动开始时间
    int s[N];
    // 存储活动结束时间
    int f[N];
    // 存储被安排的活动编号     
    int b[N];                                          
    int n, i, sum = 0;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) 
    {
        scanf("%d%d", &s[i], &f[i]);
    }
    sum = Greedy(n, s, f, b);
    printf("%d", sum);
    return 0;
}