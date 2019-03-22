#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[3000], b[3000];
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int i, n, j, sum, k, f, ji;
    while (scanf("%d", &n) && n != 0)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &b[i]);
        sort(a, a + n, cmp);
        sort(b, b + n, cmp);
        for (i = 0; i < n; i++)
            printf("%d  ", a[i]);
        printf("\n");
        for (i = 0; i < n; i++)
            printf("%d  ", b[i]);

        ji = 0; //   记录 king  比赛用的马  循环跳出的判定条件
        i = j = sum = 0;
        k = n - 1;
        f = n - 1;
        while (1)
        {
            printf("sum = %d\n", sum);
            if (ji == n)
                break; //   king  的马全部比完后跳出
            if (b[j] > a[i])
            {
                sum -= 200;
                j++;
                k--;
                ji++;
                continue;
            } //如果king的比tian的快马快 用tian的慢马对king的快马
            if (b[j] == a[i])
            { //如果相等
                if (b[f] < a[k])
                {
                    f--;
                    k--;
                    sum += 200;
                    ji++;
                    continue;
                } //看两人的慢马 tian的慢马比king的慢马快则比
                if (b[j] > a[k])
                {
                    sum -= 200;
                    k--;
                    j++;
                    ji++;
                }
                else
                {
                    k--;
                    j++;
                    ji++;
                }
                continue;
            }
            if (b[j] < a[i])
            {
                sum += 200;
                j++;
                i++;
                ji++;
                continue;
            } //如果tian的比king的快马快 直接比
        }
        printf("%d\n", sum);
    }
}

/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stdlib.h>
using namespace std;
#define N 1100

int ga[N],gt[N];


int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",gt+i);
        for(int i=0;i<n;i++)
            scanf("%d",ga+i);
        sort(ga,ga+n);
        sort(gt,gt+n);
        int ans=0;
        int ab,ad,tb,td;
        ab=0,ad=n-1; tb=0,td=n-1;
        int sign=0;
        while(1)
        {
            if(sign==0)
            {
                if(gt[tb]>ga[ab])
                {
                    ans++;
                    tb++; ab++;
                    if(tb>td) break;
                }
                else if(gt[tb]<ga[ab])
                {
                    if(ga[ad]>gt[tb]) ans--;
                    tb++; ad--;
                    if(tb>td) break;
                }
                else
                {
                    if(ga[ad]==gt[td])
                    {
                        if(ga[ad]>gt[tb]) ans--;
                        tb++;ad--;
                        if(tb>td) break;
                    }
                    else
                    {
                        sign=1; //否者交换方式
                    }
                }
            }
            else
            {
                if(gt[td]>ga[ad])
                {
                    ans++;
                    td--;ad--;
                    if(tb>td) break;
                }
                else if(gt[td]<ga[ad])
                {
                    ans--;
                    tb++; ad--;
                    if(tb>td) break;
                }
                else
                {
                    if(ga[ab]==gt[tb])
                    {
                        if(ga[ad]>gt[tb]) ans--;
                        tb++; ad--;
                        if(tb>td) break;
                    }
                    else
                    {
                        sign=0;
                    }
                }
            }
        }
        printf("%d\n",ans*200);
    }
    return 0;
}*/