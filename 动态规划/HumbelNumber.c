#include<stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define N 5900

int main(void)
{
    long long int a[N];
    char str[21][5] = {{"th"},{"st"},{"nd"},{"rd"},{"th"},{"th"},
                        {"th"},{"th"},{"th"},{"th"},{"th"},
                        {"th"},{"th"},{"th"},{"th"},{"th"},
                        {"th"},{"th"},{"th"},{"th"},{"th"}
                        };
    int i, b, c, d, e;
    b = c = d = e = 1;
    a[1] = 1;
    i = 1;
    while(i < N-1)
    {
        a[++i] = min(min(2 * a[b], 3 * a[c]), min(5 * a[d], 7 * a[e]));
        if(a[i] == 2 * a[b])
            b++;
        if(a[i] == 3 * a[c])
            c++;
        if(a[i] == 5 * a[d])
            d++;
        if(a[i] == 7 * a[e])
            e++;
        //printf("b=%d c=%d d=%d e=%d\n",b,c,d,e);
    }
    int n;
    while(scanf("%d", &n)) 
    {
        if(n == 0)
            break;
        if(n <= 20)
            printf("The %d%s humble number is %lld.\n",n , str[n], a[n]);
        else 
            printf("The %d%s humble number is %lld.\n",n , str[n % 10], a[n]);
    }
    return 0;
}