#include <stdio.h>
#include <stdlib.h>

double function(double x)
{
    double y = 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
    return y;
}

int main(void)
{
    int i, j, T;
    double x, y, c;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
        if (y >= function(0) && y <= function(100))
        {
            double a = 0, b = 100;
            while ((b - a) > 1e-10)
            {
                c = (a + b) * 0.5;
                if (function(c) > y)
                {
                    b = c;
                }
                else
                {
                    a = c;
                }
            }
            printf("%.4lf\n", c);
        }
        else
        {
            printf("No solution!\n");
        }
    }
    return 0;
}
