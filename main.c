#include <stdio.h>
#include <math.h>
const long double PI = 3.14159265358979;

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int main(void)
{
    int m, n;
    long double r, y, s1, s2, sr;
    int ax, ay, bx, by;
    scanf("%d%d%Lf", &m, &n, &r);
    scanf("%d%d%d%d", &ax, &ay, &bx, &by);
    s1 = fabs((ay - by) / n) * r;
    sr = (min(ay, by) / n) * r;
    s1 += PI * sr * fabs(ax - bx) / m;
    s2 = (ay * r) / n + (by * r) / n;
    if (s1 > s2)
        printf("%Lf\n", s2);
    else
        printf("%Lf\n", s1);

    return 0;
}