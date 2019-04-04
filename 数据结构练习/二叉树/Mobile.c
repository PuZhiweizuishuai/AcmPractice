#include <stdio.h>

int flag = 1;
int judge()
{
    int wl, a, wr, b;
    scanf("%d%d%d%d", &wl, &a, &wr, &b);
    if (wl == 0)
    {
        wl = judge();
    }
    if (wr == 0)
    {
        wr = judge();
    }

    if (wl * a == wr * b)
    {
        return wl + wr;
    }
    else
    {
        flag = 0;
        return wl + wr;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        flag = 1;
        judge();
        if (flag)
            printf("YES\n\n");
        else
            printf("NO\n\n");
    }
}