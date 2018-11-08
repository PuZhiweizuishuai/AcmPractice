#include<stdio.h>
#define N 1000

void TheSieveOfEratosthenes();

int main(void)
{
    TheSieveOfEratosthenes();
    return 0;
}
 
/* 
 埃拉托色尼筛选法
 主要思想：
（1）先把1, 0删除（现今数学界1既不是质数也不是合数)
（2）读取队列中当前最小的数2，然后把2的倍数删去
（3）读取队列中当前最小的数3，然后把3的倍数删去
（4）读取队列中当前最小的数5，然后把5的倍数删去
（5）读取队列中当前最小的数7，然后把7的倍数删去
（6）如上所述直到需求的范围内所有的数均删除或读取
*/
void TheSieveOfEratosthenes()
{
    int i, j;
    int isPrime[N];
    // 默认都是素数
    for(i = 0; i < N; i++)
        isPrime[i] = 1;
    
    // 将1和0排除
    isPrime[0] = isPrime[1] = 0;

    for(i = 2; i < N; i++)
    {
        // 到4的时候因为4是2的倍数已经被提出，所以不会进入，后续数字同理
        if(isPrime[i])
        {
            for(j = i + i; j < N; j = j + i)
                isPrime[j] = 0;
        }
    }
    printf("%d",isPrime[11]);
}