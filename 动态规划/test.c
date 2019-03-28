
#include<stdio.h>
#include<string.h>
#define maxn 101
#define max(a,b) a>b?a:b
int main()
{
	int tCase;
	int cash,kind,cost[maxn],get[maxn],num[maxn],f[10000];
	int i,j,k;
	scanf("%d",&tCase);
	while(tCase--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&cash,&kind);
		for(i=1;i<=kind;i++)
		{
			scanf("%d%d%d",&cost[i],&get[i],&num[i]);
		}
		for(i=1;i<=kind;i++)
		{
			for(j=1;j<=num[i];j++)
			{
				for(k=cash;k>=cost[i];k--)
				{
					f[k]=max(f[k],f[k-cost[i]]+get[i]);
				}
			}
		}
		printf("%d\n",f[cash]);
	}
	return 0;

}