/*
n = a % 9973

n = a - (a/9973)*9973

令 (a / b) = x

n = a-x*9973

n+x*9973 = a

bx = a

令a/9973 = y

bx-(a/9973)*9973

(a / b) % 9973

bx-9973y = n
b(x/n)-(9973)*(y/9973)

ax + by = 1
*/
#include <iostream>
using namespace std;
int MOD(int a, int b)
{
    return (a % b + b) % b;
}

int ExGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = ExGcd(b, MOD(a, b), x, y);
    //cout << r << endl;
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}

int main()
{
    int x, y, n, B, T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &B);
        ExGcd(B, 9973, x, y);
        if (x < 0)
            x += 9973;
        //printf("x=%d\n", x%9973);
        x *= n;
        
        printf("%d\n", x % 9973);
    }
    return 0;
}