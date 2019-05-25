#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[])
{
    int boxA,boxB,boxC,boxD,boxE,boxF;//不同底面积箱子数量
    int left2x2,left1x1;
    int countBox;//使用大箱子数量
    
    while(cin>>boxA>>boxB>>boxC>>boxD>>boxE>>boxF)
    {
        //结束条件
        if (boxA == 0 && boxB == 0 && boxC == 0 && boxD == 0 && boxE == 0 && boxF == 0)
        {
            break;
        }
        //体积为4、5、6的有一个就需要一个箱子，体积为3的需要boxC / 4个箱子
        countBox = boxD + boxF + boxE + (boxC + 3) / 4;
        
        //剩余的空间我们采取贪心的策略，先放2 * 2的箱子，4 * 4的箱子还剩下boxD * 5个2 * 2的空间
        left2x2 = boxD * 5;
        
        //对于3 * 3底面积的需要分情况讨论
        if (boxC % 4 == 3) //3 * 3的箱子装完了还剩下3个，只留下了1个2 * 2的空间
        {
            left2x2 += 1;
        }
        else if (boxC % 4 == 2) //这种情况下留下了3个2 * 2的空间
        {
            left2x2 += 3;
        }
        else if (boxC % 4 == 1) //注意哦，这种情况下最多可以留下5个2 * 2的空间哈
        {
            left2x2 += 5;
        }
        
        if (left2x2 < boxB)
        {
            countBox += (((boxB - left2x2) + 8) / 9);  //2 * 2箱子没地方的，开新箱子。
        }
        //解决了2 * 2的空间还剩下1 * 1的,总体积减去所有其他箱子的体积，就剩下1 * 1的空间了。
        left1x1 = 36 * countBox - 36 * boxF - 25 * boxE - 16 * boxD - 9 * boxC - 4 * boxB;
        if  (left1x1 < boxA)//空间不够，加大箱子
        {
            countBox += (((boxA - left1x1) + 35) / 36);
        }
        cout<<countBox<<endl;
    }
    return 0;
}