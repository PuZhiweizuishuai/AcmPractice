#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
double a[2][10010],b[10010];
int n,count,j;
double l,w;                
void search(double le)    //区间覆盖
{
    for(int i=0;i<j;i++)
        if(a[0][i]<=le&&a[1][i]>le&&a[1][i]>b[count])    
            b[count]=a[1][i];
    if(b[count]!=0&&b[count]<l)
    {
        count++;
        search(b[count-1]);
    }
}
int main(void)
{ 
    while(scanf("%d%lf%lf",&n,&l,&w)!=EOF)
    {
        double o,r,nr;            //必须用double
        j=0;
        count=0;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&o,&r);
            if(r<=w/2.0) continue;                     //不需考虑的情况
            nr=sqrt(r*r-w*w/4.0);                     //预处理
            a[0][j]=o-nr;                              
            a[1][j]=o+nr;
            j++;
        }
        search(0);
        if(b[count]<l)
            printf("-1\n");
        else
            printf("%d\n",count+1);
    }
    return 0;
}