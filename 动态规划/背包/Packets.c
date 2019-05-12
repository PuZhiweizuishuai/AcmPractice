#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
int judge(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] != 0)
            return 1;
    }
    return 0;
}

int pockets(int a[], int n)
{
    // 6*6的单独一箱
    int sum = a[5];
    // 5*5
    sum += a[4];
    // 剩余用 1*1填充
    a[0] = max(0, a[0] - 11 * a[5]);
    // 4*4
    sum += a[3];

    if (a[1] < 5 * a[3])
    {
        // 2*2填充后再用1*1
        a[0] = max(0, a[0] - (5 * a[3] - a[1]));
    }
    a[1] = max(0, a[1] - 5 * a[3]);
    // 3*3
    sum += (a[2] + 3) / 4;
    a[2] %= 4;
    if (a[2] == 1)
    {
        if (a[1] < 5)
            a[0] = max(0, a[0] - (27 - 4 * a[1]));
        else
            a[0] = max(0, a[0] - 7);
        a[1] = max(0, a[1] - 5);
    }
    else if (a[2] == 2)
    {
        if (a[1] < 3)
            a[0] = max(0, a[0] - (18 - 4 * a[1]));
        else
            a[0] = max(0, a[0] - 6);
        a[1] = max(0, a[1] - 3);
    }
    else if (a[2] == 3)
    {
        if (a[1] < 1)
            a[0] = max(0, a[0] - (9 - 4 * a[1]));
        else
            a[0] = max(0, a[0] - 5);
        a[1] = max(0, a[1] - 1);
    }
    // 2*2
    sum += (a[1] + 8) / 9;
    a[1] %= 9;
    if (a[1])
        a[1] = max(0, a[0] - (36 - 4 * a[1]));

    // 1*1
    sum += (a[0] + 35) / 36;
    return sum;
}

int main(void)
{
    int n[6], i;
    while (1)
    {
        for (i = 0; i < 6; i++)
            scanf("%d", &n[i]);
        if (judge(n, 6) == 0)
            break;
        printf("%d\n", pockets(n, 6));
    }
    return 0;
}
