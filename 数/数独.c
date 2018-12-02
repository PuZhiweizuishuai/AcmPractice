#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * 判断一个 9 * 9 的数独是否正确
*/

/**
 * 判断行
*/
int hang(int a[9][9], int n)
{
    int i,j, b[9];
    for(i = 0; i < 9; i++)
    {
        b[i] = a[n][i];
    }
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(i == j)
                continue;
            if(a[n][i] == b[j])
                return 0;
        }
    }
    return 1;
}
 
/**
 * 判断列
*/
int lie(int a[9][9], int n)
{
    int i,j, b[9];
    for(i = 0; i < 9; i++)
    {
        b[i] = a[i][n];
    }
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(i == j)
                continue;
            if(a[i][n] == b[j])
                return 0;
        }
    }
    return 1;
}

/**
 * 判断宫， n， m为宫的起点
*/
int gong(int a[9][9], int n, int m)
{
    int b[9], i, j,k = 0,x,y;
    for(i = n,x=0; i < n+3; i++,x++)
    {
        for(j = m,y=0; j < m+3; j++,y++)
        {
            b[k] = a[i][j];
            k++;
        }
    }
    k = 0;
    for(i = n,x =0; i < n+3; i++,x++)
    {
        for(j = m,y=0; j < m+3; j++,y++)
        {
            if(k == x*y)
                continue;
            if(b[k] == a[i][j])
                return 0;
            k++;
        }
    }
    return 1;
}
 
/**
 * 总体判断
*/
int Judge()
{
    int a[9][9], i, j;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            scanf("%d",&a[i][j]);
 
    for(i = 0; i < 9; i++)
    {
        if(hang(a,i) == 0)
            return 0;
        if(lie(a,i) == 0)
            return 0;
    }
    for(i = 0; i < 9; i+=3)
        for(j = 0; j < 9; j+=3)
        {
            if(gong(a,i,j) == 0)
                return 0;
        }
 
    return 1;
}
 
 
 
int main(void)
{
    int T, n;
    scanf("%d",&T);
 
    while(T--)
    {
        printf("%d\n",Judge());
 
    }
    return 0;
}
 
/**************************************************************
    Problem: 2641
    User: 201741010102
    Language: C
    Result: Accepted
    Time:7 ms
    Memory:1064 kb
****************************************************************/
