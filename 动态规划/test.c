#include <stdio.h>


int main(void)
{
    int a,b;
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        b = 0;
        while(n--)
        {
           scanf("%d", &a);
            b += a;
        }
        printf("%d\n", b);
        
    }
    
    return 0;
}