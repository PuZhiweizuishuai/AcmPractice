#include <stdio.h>
#include <math.h>
/**
 * 给定一个 32 位有符号整数，将整数中的数字进行反转。
 * 假设我们的环境只能存储 32 位有符号整数，
 * 其数值范围是 [−2^31,  2^31 − 1]。
 * 根据这个假设，如果反转后的整数溢出，则返回 0。
 * leetcode 7 https://leetcode-cn.com/problems/reverse-integer/
*/

int reverse(int x);

int main(void)
{
    printf("%d", reverse(123));

    return 0;
}

int reverse(int x)
{
    int a[100], flag = 0, fu = 0, number = 0;
    int i = 0;
    if (x < 0)
    {
        fu = 1;
        x = -x;
    }
    while (x)
    {
        a[i] = x % 10;
        x = x / 10;
        // 防止溢出
        if (number > INT_MAX / 10 || (number == INT_MAX / 10 && a[i] > 7))
            return 0;
        if (number < INT_MIN / 10 || (number == INT_MIN / 10 && a[i] < -8))
            return 0;
        number = number * 10 + a[i];
        i++;
    }
    if (fu == 1)
        number = -number;
    return number;
}