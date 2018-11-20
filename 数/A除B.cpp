#include <iostream>
using namespace std;
/**
 * hdu 1576 A/B
*/
int MOD(int a, int b)
{
    return (a % b + b) % b;
}
/**
 * 欧几里得扩展算法递归实现
*/
int ExGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = ExGcd(b, MOD(a, b), x, y);
    cout << r << endl;
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}
/**
 * 欧几里得算法非递归实现
*/
int EXGCD(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int m,m1,n,n1,c,d,q,r,t;
    m1 = n = 1;
    m = n1 = 0;
    c = a;
    d = b;
    q = c / d;
    r = c % d;
    while(r)
    {
        c = d;
        d = r;
        t = m1;
        m1 = m;
        m = t - q * m;
        t = n1;
        n1 = n;
        b = t - q * b;
        q = c / d;
        r = c % d;
    }
    x = m;
    y = n;
    return d;
}

int main()
{
    int x ,y,n,B,T;
    cin >> T;
    while(T--)
    {
        cin >> n >> B;
        EXGCD(B,9973,x,y);
        if(x < 0)
            x += 9973;
        x *= n;
        cout << x % 9973 << endl;
    }
    return 0;
}