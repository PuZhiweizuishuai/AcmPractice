#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"function_dec.h"

void color(short x) //自定义函根据参数改变颜色   
{
    if (x >= 0 && x <= 15)//参数在0-15的范围颜色  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //只有一个参数，改变字体颜色   
    else//默认的颜色白色  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
/*
颜色函数SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),前景色 | 背景色 | 前景加强 | 背景加强);
前景色：数字0-15 或 FOREGROUND_XXX 表示  （其中XXX可用BLUE、RED、GREEN表示）
前景加强：数字8 或 FOREGROUND_INTENSITY 表示
背景色：数字16 32 64 或 BACKGROUND_XXX 三种颜色表示
背景加强： 数字128 或 BACKGROUND_INTENSITY 表示
主要应用：改变指定区域字体与背景的颜色
前景颜色对应值：
　　0=黑色                8=灰色　　
  　1=蓝色                9=淡蓝色        十六进制        　　
   2=绿色                10=淡绿色       0xa        　　
   3=湖蓝色              11=淡浅绿色     0xb　
   4=红色                12=淡红色       0xc　　
   5=紫色                13=淡紫色       0xd        　　
   6=黄色                14=淡黄色       0xe        　　
   7=白色                15=亮白色       0xf
   也可以把这些值设置成常量。
*/



void title(void)
{
    printf("\n\n\n    		+------------------------------------------------------+\n");
    printf("    		|                                                      |\n");
    printf("    		|                学生信息成绩管理系统                  |\n");
    printf("    		|                                                      |\n");
    printf("    		|	                                               |\n");
    printf("    		|                    版本   V3.0                       |\n");
    printf("    		|                    作者   蒲致威                     |\n");
    printf("    		|                 学号   201741010102                  |\n");
    printf("    		|                 发布时间 2018/03/11                  |\n");
    printf("    		+------------------------------------------------------+\n\n");
    arrow();
    printf("\n\n\n");
    printf("                                                                       北京时间：");
    Times();
    printf("\n                                                       配音：贾维斯（J.A.R.V.I.S）保罗·贝坦尼（Paul Bettany）\n");
}

void arrow(void)
{
    int i, j;
    for (i = 0; i < 5; i++) printf(" "); printf("*");
    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < 12; i++) printf(" "); 
        printf("*");
    }
    printf("\n");


    for (i = 0; i < 5; i++) printf(" ");
    printf("***");
    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < 10; i++) printf(" ");
        printf("***");
    }
    printf("\n");

    for (j = 0; j < 7; j++)
    {
        for (i = 0; i < 10; i++) printf("*");
        for (i = 0; i < 3; i++) printf(" ");
    }
    printf("\n");

    for (j = 0; j < 7; j++)
    {
        for (i = 0; i < 12; i++)
            printf("*");
        printf(" ");
    }
    printf("\n");

    for (j = 0; j < 7; j++)
    {
        for (i = 0; i < 10; i++) printf("*");
        for (i = 0; i < 3; i++) printf(" ");
    }
    printf("\n");


    for (i = 0; i < 5; i++) printf(" ");
    printf("***");
    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < 10; i++) printf(" ");
        printf("***");
    }
    printf("\n");

    for (i = 0; i < 5; i++) printf(" ");
    printf("*");
    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < 12; i++) printf(" ");
        printf("*");
    }
    printf("\n");
}

void ShowMenu(void)
{
    printf("    			+------------------------------------------------------+\n");
    printf("    			|                学生信息成绩管理系统                  |\n");
    printf("    			+------------------------------------------------------+\n");
    printf("    			|    功能选择：                                        |\n");
    printf("    			|             1.学生成绩信息查询                       |\n");
    printf("    			|             2.学生成绩信息录入                       |\n");
    printf("    			|             3.学生成绩排序                           |\n");
    printf("    			|             4.学生成绩修改或删除                     |\n");
    printf("    			|             5.成绩分析                               |\n");
    printf("    			|             6.显示所有学生信息                       |\n");
    printf("    			|             7.保存学生信息到.txt格式文本文件         |\n");
    printf("    			|             8.密码设置                               |\n");
    printf("    			|             9.退出系统                               |\n");
    printf("    			+------------------------------------------------------+\n\n");

    printf("                                                                       北京时间：");
    Times();
}

void Form(void)
{
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  编号        姓名         性别     年龄          专业          数学            英语           专业课           选修课          总分          平均分\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void ModityAndDellUI(void)
{
    printf("    			+------------------------------------------------------+\n");
    printf("    			|                学生成绩修改和删除                    |\n");
    printf("    			+------------------------------------------------------+\n");
    printf("    			|             1.修改成绩                               |\n");
    printf("    			|             2.删除编号为 ? 的学生成绩                |\n");
    printf("    			|             3.删除所有学生成绩                       |\n");
    printf("    			|             4.返回上一级                             |\n");
    printf("    			+------------------------------------------------------+\n");
}


float f(float x, float y, float z)                                                 //彩蛋相关函数
{
    float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}                    

float h(float x, float z)														//彩蛋相关函数
{
    float y;
    for (y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (f(x, y, z) <= 0.0f)
            return y;
    return 0.0f;
}                        

void caidan(void)
{
    
    float x,z;
    for (z = 1.5f; z > -1.5f; z -= 0.05f) 
    {
        for (x = -1.5f; x < 1.5f; x += 0.025f) 
        {
            float v = f(x, 0.0f, z);
            if (v <= 0.0f) 
            {
                float y0 = h(x, z);
                float ny = 0.01f;
                float nx = h(x + ny, z) - y0;
                float nz = h(x, z + ny) - y0;
                float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else
                putchar(' ');
        }
        putchar('\n');
        
    }

}

void PasswordSettingUI(void)
{
    printf("    			+------------------------------------------------------+\n");
    printf("    			|                    密码修改与设置                    |\n");
    printf("    			+------------------------------------------------------+\n");
    printf("    			|             1.修改密码                               |\n");
    printf("    			|             2.忘记密码                               |\n");
    printf("                	|             3.返回上一级                             |\n"); 
    printf("    			+------------------------------------------------------+\n\n");

    printf("    			+------------------------------------------------------+\n");
} 

void FindStudentUI(void)
{
    printf("    			+------------------------------------------------------+\n");
    printf("    			|                      学生成绩查找                    |\n");
    printf("    			+------------------------------------------------------+\n");
    printf("    			|    功能选择：                                        |\n");
    printf("    			|             1.按姓名查找                             |\n");
    printf("    			|             2.按学号查找                             |\n");
    printf("    			|             3.退出查找                               |\n");
    printf("    			+------------------------------------------------------+\n\n");
    printf("    			+------------------------------------------------------+\n");
} 


void SotrUI(void)									//24.排序uI 
{
    printf("    			+------------------------------------------------------+\n");
    printf("    			|                      学生成绩排序                    |\n");
    printf("    			+------------------------------------------------------+\n");
    printf("    			|    功能选择：                                        |\n");
    printf("    			|             1.按总分排序                             |\n");
    printf("    			|             2.按数学成绩排序                         |\n");
    printf("    			|             3.按英语总分排序                         |\n");
    printf("    			|             4.按专业课总分排序                       |\n");
    printf("    			|             5.按选修课总分排序                       |\n");
    printf("    			|             6.退出排序                               |\n");
    printf("    			+------------------------------------------------------+\n\n");
    printf("    			+------------------------------------------------------+\n");
    printf("                             请输入你的选择：");
}

void SaveUI(void)
{
    printf("    			+------------------------------------------------------+\n");
    printf("    			|                      学生成绩输出                   |\n");
    printf("    			+------------------------------------------------------+\n");
    printf("    			|    功能选择：                                        |\n");
    printf("    			|             1.按总分排序输出                         |\n");
    printf("    			|             2.按数学成绩排序输出                     |\n");
    printf("    			|             3.按英语总分排序输出                     |\n");
    printf("    			|             4.按专业课总分排序输出                   |\n");
    printf("    			|             5.按选修课总分排序输出                   |\n");
    printf("    			|             6.按学号排序输出                         |\n");
    printf("    			|             7.退出成绩输出                           |\n");
    printf("    			+------------------------------------------------------+\n\n");
    printf("    			+------------------------------------------------------+\n");
    printf("                             请输入你的选择：");
}













