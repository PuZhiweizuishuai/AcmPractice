#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[2100], f[2100];
int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));
    //f[i][j]表示第i次取数后右面共取j个的最大值
    //f[i][j]=max(f[i-1][j-1]+i*a[n-j+1],f[i-1][j]+i*a[i-j]);(j<=i)
    f[0] = a[1];
    f[1] = a[n];
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j)
                f[j] = max(f[j - 1] + i * a[n - j + 1], f[j] + i * a[i - j]);
            else
                f[j] += i * a[i];
        }
    }
    int _max = (1 << 31);
    for (int i = 0; i <= n; i++)
        if (f[i] > _max)
            _max = f[i];
    printf("%d\n", _max);

    return 0;
}
