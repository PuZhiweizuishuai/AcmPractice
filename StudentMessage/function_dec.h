#ifndef functiom_dec
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100
#define NAME 20
#define COURSE 4
#include<mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

FILE *DATA;


typedef enum{MAN, WOMAN} SEX;

typedef struct tagStudent
{
    long int num;        						    //学生的编号
    
	char name[20];  						    //学生的姓名
    
	SEX sex;        						    //学生的性别
    
	int age;        						    //学生的年龄
    
	char major[20]; 						    //学生的专业
    
	float score[COURSE];                        //学生成绩
	
	float add ;									//学生总分 
	
	float aveg;									//学生平均分 
    
	struct tagStudent *next;					//链表下一个节点的指针

}STUDENT,*PSTUDENT;

STUDENT g_head;                                //头节点

STUDENT temps;

STUDENT te;

void color(short x);                 //1.颜色函数声明

void title(void);			         //2.主界面标题

void arrow(void);			         //3.箭头

void ShowMenu(void);				 //4.显示菜单

int GetMenuChoose(void);                 //5.获取用户选择

void caidan(void);			         //6.功能错误时的彩蛋

PSTUDENT CreateStudent(void);				//7.创建一个节点,它会返回一个新创建的学生信息节点的指针

int AddStudent(PSTUDENT pstu);				//8.把学生信息节点加入到链表中

PSTUDENT GetPrevAddr(int num);					//9.返回指定编号学生节点的上一个节点的指针

void Form(void);                                 //10.输出数据上部的表头

void FindStudentUI(void);					//11.查找用户信息的Ui

void FindStudent(void);						//12.查询用户信息 

void FindStudentNmae(void);					//13.按姓名查找学生信息 

void  ShowOneStudent(void);					//14.按学号查找学生信息 

void ShowAll(void);                       //15.显示所有学生信息 

int ShowStudentCount(void);                       //16.显示信息数量

void ModityAndDellUI(void);                           //17.修改和删除的UI

void ModityAndDell(void);						//18.修改学生信息和删除 

void ModityStudent(int num);                 //19.修改学生信息，参数为要修改的学生的编号

int Question(const char *pstr);                   //20.获取用户的选择

int GetInputNum(void);               //21.获取用户输入的学生的编号

void DelStudent(int num);                 //22.删除编号为num的学生信息

void DelAll(void);									//23.删除所有的学生信息

void SotrUI(void);									//24.排序uI 


void SortTotal(void);	                           //25.对学生信息进行排序

void SortID(void);										// 默认使用id排序

void SortScore(int n);                                  //科目排序，n为科目代码 

void Sort(void);
							
void ScoreAnalysis(void);                            //成绩分析

void AllScoreAnalysis(int a,int b,int k,int q);							//数学和英语和专业和选修成绩分析，参数a为课程代码，b为分数线代码，k为课程代码 ，q为输出判断                    

void ReadPassword(void);												//读取文件中的密码

int PasswordVer(char *str);												//验证密码 

int Modify(void);												//修改密码 

int PasswordKey(void);												//

void PasswordSettingUI(void);												//密码设置UI 

void PasswordSetting(void);																						//密码设置 


void DelAllPassword(void);									//选择忘记密码后删除所有的学生信息

void FileAdRead(void);									//数据文件管理，负责读取数据 

void SaveFile(void);					                    //保存数据

int Times(void);										//获取当前时间

int TimesTo(FILE *fp);                                  //36.保存时间到文件 

void Save(int n);										//保存到txt文件

void SaveScore(void);									//获取保存的选择

void SaveUI(void);








#endif

