#include<stdio.h>


int main(void)
{
    long long int a, head, secore;
    scanf("%lld", &a);
    head = a * a - a + 1;
    secore = a * a * a;
    printf("%lld*%lld*%lld=%lld=", a, a, a, secore);
    while(secore)
    {
        printf("%lld+", head);
        secore -= head;
        head += 2;
    }
    printf("\b");
    return 0;
}

