#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 15010
/**
 * n 个洒水器
 * length 草坪长度
 * width 草坪宽度
*/
double position, radius, edge[2][MAX], b[MAX];
double length, width;
int count, j;
void search(double le)
{
    int i;

    for (int i = 0; i < j; i++)
    {
        if (edge[0][i] <= le && edge[1][i] > le && edge[1][i] > b[count])
            b[count] = edge[1][i];
    }

    if (b[count] != 0 && b[count] < length)
    {
        count++;
        search(b[count - 1]);
    }
}

int main(void)
{
    int i, num;

    double nr;
    while (scanf("%d%lf%lf", &num, &length, &width) != EOF)
    {
        j = 0;
        count = 0;
        memset(b, 0, sizeof(b));
        for (i = 0; i < num; i++)
        {
            scanf("%lf%lf", &position, &radius);
            // 忽略掉圆不能覆盖矩形草坪的情况
            if (radius < width / 2.0)
                continue;
            // 计算圆与矩形上下边缘的交点
            nr = sqrt(radius * radius - (width * width) / 4.0);
            edge[0][j] = position - nr;
            edge[1][j] = position + nr;
            j++;
            
        }
        search(0);
        if (b[count] < length)
            printf("-1\n");
        else
            printf("%d\n", count + 1);
    }

    return 0;
}