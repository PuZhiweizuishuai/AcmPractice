#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main(void)
{
    double m, n, r;
    int ax, ay, bx, by;
    cin >> m >> n >> r >> ax >> ay >> bx >> by;

    double s1 = abs((ay - by) / n) * r;
    double rr = (min(ay, by) / n) * r;
    s1 += pi * rr * abs(ax - bx) / m;
    double s2 = (ay * r) / n + (by * r) / n;
    if(ay ==0 && by == 0)
        printf("0\n");
    else
        printf("%.14Lf\n", min(s1, s2));
    return 0;
}
