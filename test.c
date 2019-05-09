#include <stdio.h>
#include <math.h>
#define ZERO 0.000001

double fun(double x)
{
    return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

double root(double a, double b)
{
    double funmid;
    while (fun(a)*fun(b)>0)
    {
        scanf("%lf%lf",&a,&b);
    }

    while (1)
    {
        double mid = (a + b) / 2;
        funmid = fun(mid);
        //printf("%lf %lf  %lf  %lf\n", a, b, mid, fun(mid));
        if (fabs(funmid - 0) <= ZERO)
        {
            return mid;
        }
        else if (funmid * fun(a) > 0)
            a = mid + ZERO;
        else 
            b = mid - ZERO;
        /*if (fun(a) * fun(b) >= 0)
            scanf("%lf%lf", &a, &b);*/
    } 
}

int main(void)
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.6lf\n", root(a, b));
    return 0;
}