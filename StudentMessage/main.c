#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"function_dec.h"


FILE *PAS;										//密码文件指针

char Password[20] = "admin"; 
int yaoshi = 0;


int main(void)
{
	
	PlaySound(TEXT("Sound//Welcome Home Sir.wav"), 0, SND_FILENAME| SND_ASYNC); //.wav是要播放的音乐文件
	color(15);
	system("mode con: cols=160");
	title();
	system("pause");							//暂停
	system("cls");								//清屏 
	ReadPassword();									  //读取已有的密码
	FileAdRead();                                     //读取已有数据 

	
	int running = 1;
	while (running)
	{
		ShowMenu();
		switch(GetMenuChoose())
		{
			case 1:
				FindStudent();
				//system("pause");
				system("cls"); break;
            
			case 2:
			{
				if(PasswordKey() == 1)
				{
					system("cls");
					printf("    			+------------------------------------------------------+\n");
					printf("    			|                  学生成绩信息添加                    |\n");
					printf("    			+------------------------------------------------------+\n\n\n");
					printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					AddStudent(CreateStudent());
					yaoshi = 1;
					while( Question("是否继续录入？"))
					{
						yaoshi = 1;
						printf("\n");
						AddStudent(CreateStudent());
						printf("\n");
					}
				}
				else
					break;
				system("cls");
				break;
			}
			case 3:
				Sort();break;
			
			case 4:
				if(PasswordKey() == 1)
				{
					ModityAndDell();break;
				}
				else
					break;
			case 5:
				ScoreAnalysis(); break;
			
			case 6:
				SortID();							//默认按序号排名
				ShowAll();break;
				
			case 7:
				SaveScore(); break;
				
			case 8:
				PasswordSetting();
				yaoshi = 0; break;
				
			case 9:
				PlaySound(TEXT("Sound//See you Sir.wav"), 0, SND_FILENAME | SND_ASYNC);
				running = 0;break;
			
		}
		///system("cls");
	}
	SaveFile();																	//保存数据
	printf("谢谢使用");
	system("pause");
	return 0;

}

void ReadPassword(void)
{
	PAS = fopen("Password", "r");
	if (PAS == NULL)
	{
		PAS = fopen("Password", "w");
		fwrite(Password, sizeof(Password), 1, PAS);
		fclose(PAS);
		DATA = fopen("Data", "w");					//抹除数据

		fclose(DATA);
	}
	else
	{
		fread(Password, sizeof(Password), 1, PAS);
		fclose(PAS);
	}

}

int PasswordVer(char *str)									//密码正误判断
{
	if (strcmp(str, Password)==0)
		return 0;
	else
		return 1;
} 

int Modify(void)												//修改密码 
{
	char mima[20];
	char mima_1[20],mima_2[20];
	int i,count = 0;
	printf("请先输入现有密码（默认为：admin）：");
	scanf("%s",mima);
 
	while(PasswordVer(mima))
	{
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
		color(12);
		printf("密码错误，请重新输入:");
		scanf("%s",mima);
		count ++;
		if(count == 2)
		{
			printf("您以连续三次错误输入密码，即将为您返回上一菜单\n");
			
			count = 0;
			return 0;
		}
		color(15);
	}
	int q = 1;
	
	while(q)
	{
		printf("请输入新密码：");
		scanf("%s",mima_1);
		//fflush(stdin);
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
		printf("请再输入一次：");
		scanf("%s",mima_2);
		//fflush(stdin);
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
	

		if(strcmp(mima_1,mima_2) == 0)
			break;
		else
			printf("两次输入密码不同，请重新输入\n");
	}
	for(i = 0;i < 20;i++)
		Password[i] = mima_1[i];
	PAS = fopen("Password", "w");
	fwrite(Password,sizeof(Password),1,PAS);
	printf("密码修改成功！！！");
	fclose(PAS);
	yaoshi = 1;
	system("pause");
	system("cls"); 
	return 1;
}


int PasswordKey(void)
{
	char mima[20];
	int count = 0;
	if(yaoshi == 0)
	{
		printf("\n该功能为管理员功能请输入密码（默认密码为admin,密码验证完毕后，未关闭程序下，二次进入不需要密码）：");
		scanf("%s",mima);
		while(PasswordVer(mima))
		{
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
			printf("\n密码输入错误，请重新输入：");
			scanf("%s",mima);
			count++;
			if(count == 3)
			{
				PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
				color(12);
				printf("\n密码已错误三次以上，即将为您退回主菜单\n\n");
				printf("如忘记密码，您可以到密码设置中重置密码\n\n");
				system("pause");
				system("cls");
				color(15);
				count = 0;
				return 0;		
			}
		}
		yaoshi = 0;
		printf("密码正确！！！");
		system("pause");
		system("cls");
		return 1; 
	}
	else
		return 1;
}

void PasswordSetting(void)																					//密码设置 
{
	system("cls");
	int i;
	int running = 1;
	while(running)
	{
	
		PasswordSettingUI();
		printf("			请输入你的选择（1 or 2 or 3）：");
		while(1!=scanf("%d",&i) || i > 3 ||i < 1)
		{
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
			printf("输入错误，请重新输入：");	
		} 
		if(i == 1)
		{
		
			if(Modify() == 0)
			{
				color(12);
				printf("修改失败！\n");
				system("pause");							//暂停
				system("cls");								//清屏 
				color(15);
			}
		}
		else if(i == 2)
		{
			printf("			选择忘记密码会删除当前所有数据并将当前密码重置为admin\n");
			int panduan = 0;
			panduan = Question("			你确定要这么做吗？");
			
			switch(panduan)
			{
				case 1:
					PAS = fopen("Password", "w");
					DelAllPassword();
					Password[0] = 'a';
					Password[1] = 'd';
					Password[2] = 'm';
					Password[3] = 'i';
					Password[4] = 'n';
					Password[5] = '\0';
					fwrite(Password,sizeof(Password),1,PAS);
					printf("			密码重置成功!\n");
					fclose(PAS);
					yaoshi = 0;
					system("pause");
					system("cls");
					break;
				case 0:
					printf("您已放弃重置密码。");
					system("pause");
					system("cls");
					break;
			}
			
			
		} 
		else
		{
			running = 0;
			system("cls");
		}
	}
	system("cls");
}













