#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double function(double x, double y)
{
    return (6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x);
}

double DF(double x)
{
    return (42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x);
}

int main(void)
{
    int i, j, T;
    double x, y, c;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
        if (y >= DF(0) && y <= DF(100))
        {
            double a = 0, b = 100;
            while ((b - a) > 1e-10)
            {
                c = (a + b) * 0.5;
                if (DF(c) > y)
                {
                    b = c;
                }
                else
                {
                    a = c;
                }
            }
            printf("%.4lf\n", function(c, y));
        }
    }
    return 0;
}
