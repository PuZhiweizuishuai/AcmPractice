#include<stdio.h>
#define MAX 10000010
int isPrime[MAX];

void isprimer()
{
    int i = 0, j;

    for(i = 0; i < MAX; i++)
        isPrime[i] = 1;
    

    isPrime[0] = isPrime[1] = 0;

    for(i = 2; i < MAX; i++)
    {
        if(isPrime[i])
        {
            for(j = i + i; j < MAX; j = j + i)
                isPrime[j] = 0;
        }
    }
}


int IsPalindrome(long int iNumber)
{   
    int temp=0;  
    int number = iNumber;  
    while(number)
    {   
        temp=temp*10+(number%10);  
        number=number/10;  
    }  
    if(iNumber==temp) 
        return 1;  
    else  
        return 0;  
}  


int main(void)
{
    isprimer();
    long int a,b,temp;
    long int i;
    scanf("%ld%ld",&a,&b);
    if(b < a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    for(i = a; i <= b; i++)
    {
        if(isPrime[i] && IsPalindrome(i)) 
        {
            printf("%ld\n",i);
        }
    }
    return 0;
}