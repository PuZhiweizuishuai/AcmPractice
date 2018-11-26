/**
 * 在O(logn)时间下求出模取幂运算a^b mod n
 * 如果只想计算幂数而不需要取余的话，可以导入`limits.h`头文件，
 * 并将n设置为对应类型的最大值
 * 对应的宏如下
 *  int         ->      INT_MAX
 *  long        ->      LONG_MAX
 *  long long   ->      INT64_MAX
 * 
 * @param a 模取幂运算a^b mod n中的底数
 * @param b 模取幂运算a^b mod n中的指数
 * @param n 模取幂运算a^b mod n中的基数
*/
int Pow(const int a, const int b, const int n)
{
    if (b == 0)
        return 1 % n;
    if (b % 2 == 0)
    {
        int t = Pow(a, b / 2, n);
        return t * t % n;
    }
    if (b % 2 == 1)
    {
        int t = Pow(a, b / 2, n);
        return ((t * t) % n) * (a % n) % n;
    }
}