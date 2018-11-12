#include <stdio.h>
/**
 * 两个复数分两行，每行两个数，代表复数的实部和虚部。
 * 输出两个复数的和
*/

int main(void)
{
    int a[2], b[2];
    scanf("%d %d", &a[0], &a[1]);
    scanf("%d %d", &b[0], &b[1]);
    printf("%d %d\n", (a[0] * b[0] - a[1] * b[1]), (a[0] * b[1] + a[1] * b[0]));
    return 0;
}