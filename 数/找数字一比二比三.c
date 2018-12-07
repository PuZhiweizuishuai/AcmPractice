#include<string.h>
/**
 * 将1,2,⋯,9共9个数分成3组，分别组成3个三位数，
 * 且使这3个三位数构成1:2:3的比例，试求出所有满足条件的3个三位数。 
*/
int search(int a[], int n)
{
    int i , j;
    for(i = 0; i < n ;i ++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i] == a[j] && i != j || a[j] == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    int i,a[10],temp, j = 0;
    for(i = 192; i*3 < 987; i++)
    {
        j = 0;
        temp = i;
        while(temp)
        {
            a[j] = temp % 10;
            temp /= 10;
            j++;
        }
        temp = 2*i;
        while(temp)
        {
            a[j] = temp % 10;
            temp /= 10;
            j++;
        }
        temp = 3* i;
        while(temp)
        {
            a[j] = temp % 10;
            temp /= 10;
            j++;
        }
        if(search(a,10) == 1)
            printf("%d %d %d\n",i , 2 * i, 3 * i);
    }
    return 0;
}
