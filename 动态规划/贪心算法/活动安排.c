#include <stdio.h>
#define MAX 2000
 
int Greedy(int num, int s[], int f[])
{
 
    int preStart = 0;
    int preFinal = MAX; //保证是无限大即可
    int i;
    int temp;
    int OK = 1;
    int sel[MAX]; //用来储存相容的活动编号
    int selNum = 0;
 
    while (OK)
    {
        OK = 0;
        for (i = 0; i < num; i++)
        {
 
            if (f[i] < preFinal && s[i] >= preStart)
            { //寻找开始时间合适地情况下结束时间最早者
                preFinal = f[i];
                temp = i;
                OK = 1;
            }
        }
 
        if (preFinal != MAX)
        { //变量的重新赋值
            sel[selNum++] = temp;
            preStart = f[temp];
            preFinal = MAX;
        }
    }
    return selNum;
}
 
int main(void)
{
    int s[MAX], f[MAX];
    int n, i, sum;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &s[i], &f[i]);
    }
    sum = Greedy(n, s, f);
    printf("%d", sum);
    return 0;
}