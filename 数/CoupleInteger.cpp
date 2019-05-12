#include <bits/stdc++.h>
// 给一个n和一个k  让你求一个大于n的数，二进制有k个1，求这个数最小是多少。
using namespace std;
typedef long long ll;
int a[1000];
ll n;
ll k;
int main()
{
    scanf("%lld %lld", &n, &k);

    ll nn = n;
    int cnt = 0;
    while (nn) //用a[i]记录n的二进制 cnt记录多少位
    {
        a[cnt++] = nn % 2;
        nn /= 2;
    }
    int cnt1 = 0, flag = 0, pos; //flag标记够不够k个1  flag==1说明够 0不够  //cnt1记录二进制1的个数
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (a[i] == 1)
        {
            cnt1++;
            pos = i;
        }
        if (cnt1 == k)
        {
            flag = 1;
            a[i] = 0;
            break;
        }
    }

    if (!flag) //1 is not enough
    {
        for (int i = 0; i < cnt; i++) //倒着补0
        {
            if (a[i] == 0)
            {
                a[i] = 1;
                cnt1++;
            }
            if (cnt1 == k)
                break;
        }
        while (cnt1 < k) //补满cnt位还不够 继续往前补
        {
            a[cnt++] = 1;
            cnt1++;
        }
    }
    else //1 is enough
    {
        for (int i = 0; i < pos; i++)
            a[i] = 0;
        int flag1 = 0, pos1;
        for (int i = pos + 1; i < cnt; i++) //pos记录了第k个1的位置
        {
            if (a[i] == 0)
            {
                a[i] = 1;
                flag1 = 1;
                pos1 = i;
                break;
            }
        }
        if (!flag1) //n=1111000 k = 3  ->> 11100000
        {
            a[cnt++] = 1;
            for (int i = cnt - 2; i >= k - 1; i--)
                a[i] = 0;
            for (int i = 0; i < k - 1; i++)
                a[i] = 1;
        }
        else //n=（二进制）11011000 k=3的情况  ->>  11100000
        {
            int cnt2 = 0;
            for (int i = cnt - 1; i >= pos1; i--)
                if (a[i] == 1)
                    cnt2++;
            for (int i = 0; i < k - cnt2; i++)
                a[i] = 1;
            for (int i = k - cnt2; i < pos1; i++)
                a[i] = 0;
        }
    }
    ll ans = 0;
    ll p = 1;
    for (int i = 0; i < cnt; i++)
    {
        ans += p * (ll)a[i];
        p *= 2;
    }
    printf("%lld\n", ans); //自闭了啊啊啊啊啊啊啊啊啊啊啊啊
    return 0;
}