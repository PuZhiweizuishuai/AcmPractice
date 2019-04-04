#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    double price;
    double ans, maxNum;
    int p, a, b, c, d, n;
    while (scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n) != EOF)
    {

        ans = 0;
        maxNum = 0;
        for (i = 1; i <= n; i++)
        {
            price = p * (sin(a * i + b) + cos(c * i + d) + 2);
            if (price > maxNum)
            {
                maxNum = price;
            }
            else
            {
                if (maxNum - price > ans)
                {
                    ans = maxNum - price;
                }
            }
        }

        printf("%.6lf\n", ans);
    }
    return 0;
}