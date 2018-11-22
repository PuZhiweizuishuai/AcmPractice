#include <iostream>
/**
 * POJ 1061
 * 求 ax + by = gcd(a,b)
 * t(m-n) + kL = y - x              1
 * a = m -n;
 * b = L;
 * d = y - x;
 * t(m-n) + kL = gcd(a,b); 
 * 2 式乘以 d/gcd 就是 1
 * t2 * d/gcd 就是t1的特解
 * gcd(a,b)是d的倍数
 * d % gcd(ab) != 0        Impossible
 * 通过通解求 t 即可
*/
long long int ExGcd(long long int a, long long int b, long long int &x, long long int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long int r = ExGcd(b, a % b, x, y);
    long long int t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}

int main()
{
    long long int x, y, m, n, L;
    long long int a, b, d, t, gcd;
    while (std::cin >> x >> y >> m >> n >> L)
    {
        a = m - n;
        b = L;
        d = y - x;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        gcd = ExGcd(a, b, x, y);
        if (d % gcd != 0)
            std::cout << "Impossible" << std::endl;
        else
        {
            // x 的一个通解
            x = x * (d / gcd);
            // b / gcd这里是求通解之间的最小间隔
            // x % t 就是最小的正整数解
            t = b / gcd;
            if (x < 0)
                x = x % t + t;
            else
                x = x % t;
            std::cout << x << std::endl;
        }
    }
    return 0;
}
