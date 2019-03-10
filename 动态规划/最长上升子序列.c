#include<stdio.h>
#define N 5100
#define max(a,b) (((a) > (b)) ? (a) : (b))
int a[N];
int dp[N];
int main(void) 
{
    int i, j, n, ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) 
    {
        dp[i] = 1;
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    for(i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    printf("%d", ans);
    return 0;
}