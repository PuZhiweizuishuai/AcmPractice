#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

void sum()
{
    int N, i, j;
    int a[100][100];
    scanf("%d",&N);
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++)
            a[i][j] = 0;
    for(i = 0; i < N; i++)
        for(j =0; j <= i; j++)
            scanf("%d",&a[i][j]);


    for(i = N-1;j > 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            a[i][j] = a[i][j] + max(a[i+1][j],a[i+1][j+1]);
            //printf("a[%d][%d]=%d  a[%d][%d] = %d a[%d][%d]=%d\n",i,j,a[i][j],i+1,j,a[i+1][j],i+1,j+1,a[i+1][j+1]);
        }
        printf("\n");
    }
    printf("%d",a[0][0]);
}
int main()
{
    sum();
    return 0;
}
