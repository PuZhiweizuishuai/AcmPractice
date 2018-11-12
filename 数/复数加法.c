#include<stdio.h>


int main(void)
{
    int a[2], b[2];
    scanf("%d %d",&a[0], &a[1]);
    scanf("%d %d",&b[0], &b[1]);
    printf("%d %d",a[0]+b[0], a[1]+b[1]);
    return 0;
}