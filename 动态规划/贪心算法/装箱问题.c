#include <stdio.h>
#define max(x, y) (x > y ? x : y)
int judge(int a[])
{
    int i;
    for (i = 1; i <= 6; i++)
    {
        if (a[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

int boxNumber(int a[])
{
    int sum = 0;
    sum += a[6];
    sum += a[5];
    a[1] = max(0, a[1] - 11 * a[5]);

    sum += a[4];
    if (a[2] < 5 * a[4])
        a[1] = max(0, a[1] - (5 * a[4] - a[2]));
    a[2] = max(0, a[2] - 5 * a[4]);

    sum += (a[3] + 3) / 4;
    a[3] %= 4;
    if (a[3] == 1)
    {
        if (a[2] < 5)
            a[1] = max(0, a[1] - (27 - 4 * a[2]));
        else
            a[1] = max(0, a[1] - 7);
        a[2] = max(0, a[2] - 5);
    }
    else if (a[3] == 2)
    {
        if (a[2] < 3)
            a[1] = max(0, a[1] - (18 - 4 * a[2]));
        else
            a[1] = max(0, a[1] - 6);
        a[2] = max(0, a[2] - 3);
    }
    else if (a[3] == 3)
    {
        if (a[2] < 1)
            a[1] = max(0, a[1] - (9 - 4 * a[2]));
        else
            a[1] = max(0, a[1] - 5);
        a[2] = max(0, a[2] - 1);
    }

    sum += (a[2] + 8) / 9;
    a[2] %= 9;
    if (a[2])
        a[1] = max(0, a[1] - (36 - 4 * a[2]));

    sum += (a[1] + 35) / 36;
    return sum;
}

int main(void)
{
    int a[7], i;
    while (1)
    {
        for (i = 1; i <= 6; i++)
        {
            scanf("%d", &a[i]);
        }
        if (judge(a) == 0)
        {
            break;
        }
        printf("%d\n",boxNumber(a));
    }

    return 0;
}