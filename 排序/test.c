#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}



int main(void)
{
    int a[10];
    int i;
    
    for(i = 0; i < 10; i++) 
        scanf("%d",&a[i]);
    qsort(a,10,sizeof(a[0]),cmp);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}