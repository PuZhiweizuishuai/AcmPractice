/**
 * 请使用 clang 编译，gcc 不支持中文 
*/

#include <stdio.h>
#include <string.h>
#define 最大数(第一个数, 第二个数) 第一个数 > 第二个数 ? 第一个数 : 第二个数
#define 主函数 main
#define 空 void
#define 整型数 int
#define 输入 scanf
#define 输出 printf
#define 返回 return
#define 循环 for
#define 初始化数组函数 memset
#define 查看数据大小函数 sizeof


整型数 最大重量(整型数 背包[], 整型数 物品重量[], 整型数 物品价值[], 整型数 物品数, 整型数 不超过的最大质量)
{
    初始化数组函数(背包, 0, 查看数据大小函数(背包[0]));
    整型数 循环数一, 循环数二;
    循环(循环数一 = 0; 循环数一 < 物品数; 循环数一++)
    {
        循环(循环数二 = 不超过的最大质量; 循环数二 >= 物品重量[循环数一]; 循环数二--)
        {
            背包[循环数二] = 最大数(背包[循环数二 - 物品重量[循环数一]] + 物品价值[循环数一], 背包[循环数二]);
        }
    }
    返回 背包[不超过的最大质量];
}

整型数 主函数(空)
{
    整型数 循环数一;
    整型数 物品数, 不超过的最大质量, 物品重量[4000], 物品价值[4000], 背包[40000];
    输入("%d%d", &物品数, &不超过的最大质量);
    循环(循环数一 = 0; 循环数一 < 物品数; 循环数一++)
    {
        输入("%d%d", &物品重量[循环数一], &物品价值[循环数一]);
    }
    输出("%d\n", 最大重量(背包, 物品重量, 物品价值, 物品数, 不超过的最大质量));

    返回 0;
}