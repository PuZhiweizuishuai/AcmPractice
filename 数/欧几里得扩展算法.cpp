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
    int r = ExGcd(b, MOD(a ,b), x, y);
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
