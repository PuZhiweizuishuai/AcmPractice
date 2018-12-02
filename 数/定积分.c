#include <stdio.h>
/**
 * 已知三点，求抛物线与直线围成的面积
 * a,b,c求值使用三点式公式见
 * https://baike.baidu.com/pic/%E4%BA%8C%E6%AC%A1%E5%87%BD%E6%95%B0%E4%B8%89%E7%82%B9%E5%BC%8F/2154688/0/e61190ef76c6a7efc944e453f1faaf51f3de6660?fr=lemma&ct=single#aid=0&pic=e61190ef76c6a7efc944e453f1faaf51f3de6660
*/
long double DefiniteIntefral(long double a, long double b, long double c, long double x)
{
    return ((1.0 / 3.0) * a * x * x * x + 0.5 * b * x * x + c * x);
}

long double Result(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3)
{
    long double a, b, c, s, s1, s2, s3;
    b = ((x2 * x2 - x3 * x3) * (y1 - y2) - (x1 * x1 - x2 * x2) * (y2 - y3)) / ((x2 * x2 - x3 * x3) * (x1 - x2) - (x1 * x1 - x2 * x2) * (x2 - x3));
    a = (y1 - y2 - b * (x1 - x2)) / (x1 * x1 - x2 * x2);
    c = y1 - a * x1 * x1 - b * x1;
    //printf("a=%Lf b=%Lf c=%Lf\n",a,b,c);
    s1 = DefiniteIntefral(a, b, c, x3) - DefiniteIntefral(a, b, c, x2);
    s2 = ((y3 + y2) * (x3 - x2)) / 2.0;
    s = s1 - s2;
    if(s < 0)
        s = -s;
    return s;
}

int main(void)
{
    int T;
    long double x1, y1, x2, y2, x3, y3;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2, &x3, &y3);
        printf("%.2Lf\n", Result(x1, y1, x2, y2, x3, y3));
    }

    return 0;
}