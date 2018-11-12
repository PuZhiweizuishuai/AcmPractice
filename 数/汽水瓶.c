#include <stdio.h>
/**
 * 有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？"
 * 答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
 * 然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
 * 如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
 * 
 * 输入 0 表示结束
*/

/**
 * 输入手上的空汽水瓶，返回最多可换的汽水
*/
int MaxSodaNumber(int n);

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if(n == 0)
            return 0;
        printf("%d\n", MaxSodaNumber(n));
    }
    return 0;
}

int MaxSodaNumber(int n)
{
    // max 表示当前能换得的最大汽水瓶数
    // endMax 表示最后换得的汽水瓶数和
    int max = n / 3, endMax = 0;
    // emptyBottle 表示当前剩余汽水瓶数
    int emptyBottle = max + (n % 3);
    for (emptyBottle = max + (n % 3); emptyBottle > 1;)
    {

        endMax += max;
        max = emptyBottle / 3;
        emptyBottle = max + (emptyBottle % 3);
        // 如果剩余汽水瓶数为 2 ，则向老板借一瓶
        if (emptyBottle == 2)
            emptyBottle++;
    }
    // 补上借一瓶
    endMax += max;
    return endMax;
}