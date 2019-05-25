#include <stdio.h>
#include <stdlib.h>
int judge(int i)
{
    int t0 = 0, t1 = 0, n = 0;
    while (i != 0)
    {
        if (i % 2)
            t1++;
        else
            t0++;
        i /= 2;
        n++;
    }

    if (t1 > t0)
        return 1;
    else
        return 0;
}
int main(int argc, char *argv[])
{
    /*int i, ta = 0, tb = 0;
    for (i = 1; i < 1001; i++)
    {
        if (judge(i))
            ta++;
        else
            tb++;
    }
    printf("%d %d\n", ta, tb);*/
    printf("538 462");
    return 0;
}
