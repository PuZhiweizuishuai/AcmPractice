#include <stdio.h>
/**
 * 选择排序
*/

void SelectSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        // 查找最小值
        min = i;
        for (j = i + 1; j < n; j++)
        {
            // 保留最小值的位置
            if (a[min] > a[j])
                min = j;
        }
        // 如果 i 不是最小值，则交换
        if (min != i)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

int main(void)
{
    int a[10] = {3, 5, 9, 2, 4, 6, 8, 1, 7, 0};
    int i;
    SelectSort(a, 10);
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
    return 0;
}