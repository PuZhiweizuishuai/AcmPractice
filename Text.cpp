#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

void Read(int &p)
{
    p=0;
    int f=1;
    char c=getchar();
    while(c<'0'||c>'9') 
        f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9')
        p=p*10+c-'0',c=getchar();
    p*=f;
}

int r,c,a[1000],x,n,cnt,sp;
int main()
{
    while(1)
    {
        Read(r); Read(c); n=r*c;
        if(!r&&!c) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
            a[i] *= 100;
        }
        sort(a,a+n);
        Read(x);
        
        double V=x*1.0;
        double height=a[0];
        printf("X=%d\n", a[0]);
   
        cnt=1;
        for(int i=1;i<n;i++)
        {
            if((a[i]-a[i-1])*i<V)
            {
                V-=i*(a[i]-a[i-1]);
                cnt++; height=a[i];
            }
            else 
            {
                height+=V/i;
                V=0;
                break;
            }
        }
        if(V)  height+=V/n*1.0;
        printf("height=%.2lf\n", height);
        printf("Region %d\n",++sp);
        printf("Water level is %.2lf meters.\n",height/100);
        printf("%.2lf percent of the region is under water.\n",cnt*100.0/n);
        puts("");
    }
}
/*
#include <cstdio>
#include <cstring>

using namespace std;
bool f;
int tree()
{
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    if (wl == 0)
        wl = tree();
    if (wr == 0)
        wr = tree();
    if (wl * dl != wr * dr)
        f = false;
    return wl + wr;
}
int main()
{
    int t;
    //freopen("de.txt","r",stdin);
    scanf("%d", &t);
    while (t--)
    {
        f = true;
        tree();
        if (f)
            printf("YES\n");
        else
            printf("NO\n");
        if (t)
            printf("\n");
    }
    return 0;
}*/