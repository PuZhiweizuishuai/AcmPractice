#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"function_dec.h"


int GetMenuChoose(void)                      //获取用户选择
{
	int num;
	printf("\n    			+------------------------------------------------------+\n");
	printf("        			请输入你要选择的编号（0~9）：");
	while (1 != scanf("%d", &num) || num < 1 || num > 9)
	{
		
		//fflush(stdin);                                                      //清空输入缓冲区
		PlaySound(TEXT("Sound//Device connection fails.wav"), 0, SND_FILENAME | SND_ASYNC);
		color(12);
		caidan();
		color(15);
		printf("				你的输入有误，请重新输入:\n");
		printf("\n				PS:不要害怕，这是一个输入错误的彩蛋\n				按任意键重新输入！！！");
		system("pause");
		system("cls");
		ShowMenu();
		
		printf("\n    			+------------------------------------------------------+\n");
		printf("        			请输入你要选择的编号（0~9）：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
	}
	return num;
}


PSTUDENT CreateStudent(void)				//创建一个节点,它会返回一个新创建的学生信息节点的指针
{
	
	DATA = fopen("Data","a+");
	
	int sex;
	float ad,ave;
	PSTUDENT pstu = (PSTUDENT)malloc(sizeof(STUDENT));//在堆内存申请空间，存储学生信息
	if(!pstu)
	{ 
		printf("内存空间申请失败");
		return NULL;
	} 
	
	printf("请输入学生学号：");
	while (1 != scanf("%d", &pstu->num) || GetPrevAddr(pstu->num))
	{
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
		printf("学生编号输入错误或已经存在，请重新输入学生的编号：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
	}
	
	printf("请输入学生姓名（小于20字符）：");
	scanf("%s",pstu -> name);
	
	printf("请选择学生的性别(1.男  2.女)：");
	while(1 != scanf("%d", &sex) || sex  < 1 || sex > 2)
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("性别选择错误，请重新选择学生的性别(1.男  2.女)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }
    if(sex == 1)
        pstu->sex = MAN;
    else
        pstu->sex = WOMAN;
    
    printf("请输入学生年龄(0~100)：");
    while(1 != scanf("%d", &pstu->age) || pstu->age <  0|| pstu->age > 100)
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("年龄输入错误！请重新输入学生的年龄(10 ~ 40)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }
	
	printf("请输入学生专业（20字符以内）：");
	scanf("%s",pstu -> major);
	
	printf("请输入数学成绩(0~150)：");
	while(1 != scanf("%f", &pstu->score[0]) || pstu->score[0] <  0|| pstu->score[0] > 150)
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("成绩输入错误！请重新输入数学成绩(0 ~ 150)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }
	
	printf("请输入英语成绩（0~150）：");
	while(1 != scanf("%f", &pstu->score[1]) || pstu->score[1] <  0|| pstu->score[1] > 150)
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("成绩输入错误！请重新输入英语成绩(0 ~ 150)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }
    
	printf("请输入专业课成绩（0~300）：");
	while(1 != scanf("%f", &pstu->score[2]) || pstu->score[2] <  0|| pstu->score[2] > 300)
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("成绩输入错误！请重新输入专业课成绩(0 ~ 300)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }
	
	
	printf("请输入选修课成绩（0~300）：");
	while(1 != scanf("%f", &pstu->score[3]) || pstu->score[3] <  0|| pstu->score[3] > 300)
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("成绩输入错误！请重新输入选修课成绩(0 ~ 300)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }
	ad = (pstu->score[0]) + (pstu->score[1]) + (pstu->score[2]) + (pstu->score[3]);
	pstu -> add = ad;
	ave = ad / COURSE;
	pstu -> aveg = ave; 
	pstu->next = NULL;
	
	fwrite(pstu,sizeof(STUDENT),1,DATA);
	fclose(DATA);
	
    return pstu;
	
}


int AddStudent(PSTUDENT pstu)			//把学生信息节点加入到链表中
{
	PSTUDENT ps = &g_head;
	
    if(!pstu)
    {
        return 0;
    }

    if(GetPrevAddr(pstu->num)) 											//判断一下该学生信息是不是已经存在
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("编号为%d的学生信息已经存在！\n", pstu->num);
        free(pstu);																	//释放该节点内存空间

        return 0;
    }
    

    while(ps->next)												//while循环的作用是找到当前链表的最后一个节点
        ps = ps->next;

    ps->next = pstu; 													//把新节点加入到最后那个节点的后面
    pstu->next = NULL;

    return 1;
}


PSTUDENT GetPrevAddr(int num)					//返回指定编号学生节点的上一个节点的指针
{
	PSTUDENT pstu = &g_head;
	
	while(pstu->next)
    {
        if(pstu->next->num == num)
            return pstu;
        pstu = pstu->next;
    }

    return NULL;
}

void FindStudent(void)							//查找学生信息
{
	int q = 1,running = 1;
	int n;
	while(q)
	{
		system("cls");
		FindStudentUI();
		printf("				请输入你的选择( 1 or 2 or 3):");
		while(scanf("%d",&n) != 1 || n > 3|| n < 1)
		{
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
			printf("				输入错误，请重新输入");
			//fflush(stdin);
			while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
				
		}
		running = 1;
		while(running)
		{
			switch(n)
			{
				case 1:
					FindStudentNmae();
					running = 0;
					system("pause");
					break;
				case 2:
					ShowOneStudent();
					while(Question("是否继续查找："))
					{
						ShowOneStudent();
					}
					running = 0;
					system("pause");
				    break;
				case 3:
					running = 0;
					q = 0; break;
			}
		}
	}
		
} 


void FindStudentNmae(void)					//按姓名查找学生信息
{
	char names[20];
	
	
	int q = 1;
	int count = 0;
	//long int stuname[20]; 
	while(q)
	{
		count = 0;
		PSTUDENT pstu = &g_head;            //获取头节点 
		printf("请输入要查询的学生姓名：");
		scanf("%s",names);
		Form();
		while(pstu->next)
		{
			if(strcmp(names,(pstu->next->name)) == 0)
			{
				
				count++;
				printf("  %-10ld  ", pstu->next->num);
        		printf("%-14s", pstu->next->name);
        		printf("%-9s", pstu->next->sex == MAN ? "男" : "女");
        		printf("%-6d", pstu->next->age);
        		printf("%-20s", pstu->next->major);
        		printf("%-15.2f %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f\n",pstu->next->score[0],pstu->next->score[1],pstu->next->score[2],pstu->next->score[3],pstu->next->add,pstu->next->aveg);
			}
			pstu = pstu->next;//让指针指向下一个节点
		}
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		if(count == 0)
		{
			if(Question("没有发现该同学，是否重新查找：") == 0)
				q = 0;
			else
				q = 1;
		}
		else
		{
			printf("                                                                                                          一共发现 %d 个叫 %s 的同学。\n",count,names);
			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");		
		}
		if(count != 0)
			if(Question("是否继续查找：") == 0)
				break;
			
	}
} 

void ShowOneStudent(void)					//显按学号查询学生信息
{
	long int num;
	printf("请输入你要查询的学生编号：");
	scanf("%d",&num);
	PSTUDENT pstu = GetPrevAddr(num);			//获取要查找的学生节点的上一个节点
	if(!pstu)
    {
        printf("没有发现编号为%d的学生信息。\n", num);
        return;
    }
    pstu = pstu->next;								//将要修改的学员节点的指针改为指向自己的
	Form();
	printf("  %-10ld %-14s %-9s", num, pstu->name, pstu->sex == MAN ? "男" : "女");
	printf("%-6d %-20s",pstu->age, pstu->major );
	printf("%-15.2f %-15.2f %-15.2f %-15.2f", pstu->score[0], pstu->score[1], pstu->score[2], pstu->score[3]);
	printf("%-15.2f %-15.2f\n", pstu->add, pstu->aveg);
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}


void ShowAll(void)                       //显示所有学生信息 
{
	PSTUDENT pstu = &g_head;
	
	Form();
    while(pstu->next)
    {
        printf("  %-10ld  ", pstu->next->num);

        printf("%-14s", pstu->next->name);

        printf("%-9s", pstu->next->sex == MAN ? "男" : "女");

        printf("%-6d", pstu->next->age);

        printf("%-20s", pstu->next->major);
        printf("%-15.2f %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f\n\n",pstu->next->score[0],pstu->next->score[1],pstu->next->score[2],pstu->next->score[3],pstu->next->add,pstu->next->aveg);

        pstu = pstu->next;//让指针指向下一个节点
    }

    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("当前共有 %d 条信息                                                                                                    时间：",ShowStudentCount());
	Times();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("打印完毕！！！,如需保存此表单到文件，请返回主页面后选择功能 7。");
    system("pause");
    system("cls");
}

int ShowStudentCount(void)                       //显示信息数量
{
	int count = 0;

    PSTUDENT pstu = &g_head;

    while(pstu->next)
    {
        ++count;
        pstu = pstu->next;
    }
    //printf("\n当前共有%d位学生信息。\n", count);

    return count;
}

void ModityAndDell(void)							//修改和删除 
{
	int q = 1;

	int n,num;
	int running = 1;
	system("cls");
	//ModityAndDellUI();
	while (q)
	{
		system("cls");
		ModityAndDellUI();
		printf("\n请输入你的选择（填写序号）：");
		while (1 != scanf("%d", &n) || n < 0 || n > 4)
		{
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
			printf("输入错误，请重新输入");
			while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
		}
		running = 1;
		while (running)
		{
			printf("\n");
			switch (n)
			{
			case 1:
				printf("请输入要修改的学生学号：");
				scanf("%d", &num);
				ModityStudent(num);
				running = Question("是否继续修改"); break;

			case 2:
				printf("请输入要删除的学生学号：");
				scanf("%d", &num);
				DelStudent(num);
				running = Question("是否继续删除"); break;

			case 3:
				DelAll();
				running = 0; system("cls");break;
			case 4:
				running = 0;
				system("cls"); break;
			}
			
		}
		if (running == 0 && n == 4)
		{
			q = 0;
			system("cls");
		}
		else if(running == 1)
			q = 1;
	}
}

void ModityStudent(int num)                 //修改学生信息，参数为要修改的学生的编号
{
	PSTUDENT pstu = GetPrevAddr(num);//获取要修改的学生节点的上一个节点

    int choose;

    if(!pstu)
    {
        printf("没有编号为%d的学生信息。\n", num);
        return;
    }

    pstu = pstu->next;//将要修改的学员节点的指针改为指向自己的

    printf("\n当前学生的姓名为 %s,", pstu->name);

    if(Question("确定要修改吗？"))
    {
        printf("请输入学生的姓名(小于20字符): ");
        scanf("%20s", pstu->name);
    }

    printf("\n当前学生的性别为 %s, ", pstu->sex == MAN ? "男" : "女");

    if(Question("确定要修改吗？"))
    {
        printf("请输入学生的性别(1.男 2.女)：");
        while(1 != scanf("%d", &choose) || choose < 1 || choose > 2)
        {
            printf("输入错误，请重新输入学生的性别(1.男 2.女)：");
			while (getchar() != '\n');
        }
        if(1 == choose)
            pstu->sex = MAN;
        else
            pstu->sex = WOMAN;
    }

    printf("\n当前学生的年龄为 %d, ", pstu->age);

    if(Question("确定要修改吗？"))
    {
        printf("请输入学生的年龄(0 ~ 100)：");
        while(1 != scanf("%d", &pstu->age) || pstu->age < 0 || pstu->age > 100)
        {
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
            printf("年龄输入错误！请重新输入学生的年龄(0 ~ 100)：");
			while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
        }
    }

    printf("\n当前学生的专业为 %s, ", pstu->major);

    if(Question("确定要修改吗？"))
    {
        printf("请输入学生的专业(小于20字符):");
        scanf("%20s", pstu->major);
    }

	int i = 0;
	char cause[COURSE][10] = { "数学","英语","专业课","选修课" };
	int chengji[4] = { 150,150,300,300 };
	for (i = 0; i < COURSE;i++)
	{
		printf("\n当前学生的 %s 成绩为 %.2f, ", cause[i], pstu->score[i]);

		if (Question("确定要修改吗？"))
		{
			printf("请输入该学生的%s成绩(0~%d):",cause[i],chengji[i]);
			scanf("%f", &pstu->score[i]);
		}
	}
	
    printf("\n修改完毕！！！\n");
}

int Question(const char *pstr)                   //获取用户的选择
{
	char answer;
    printf("%s请选择（y or n）：", pstr);
    while(1 != scanf(" %c", &answer) || (answer != 'y' && answer != 'n'))
    {
		PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
        printf("输入错误！%s请重新选择（y or n）：", pstr);
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);												
    }

    if('y' == answer)
        return 1;
    else
        return 0;		
}

int GetInputNum(void)               //获取用户输入的学生的编号
{
	int num;
    printf("请输入学生的编号：");
    while(1 != scanf("%d", &num))
    {
        printf("编号输入错误！请重新输入学生的编号(整型)：");
		while (getchar() != '\n');                 //如果编译器支持可以使用 fflush(stdin);
    }

    return num;
}

void DelStudent(int num)                //删除编号为num的学生信息
{
	PSTUDENT pstu, ptmp;
    if(pstu = GetPrevAddr(num))
    {
        if(!Question("确定要删除该学生信息吗？"))
        {
            return;
        }
        ptmp = pstu->next;
        pstu->next = ptmp->next;
        free(ptmp);                                         //释放内存 
        printf("删除了编号为 %d 的学生信息。\n", num);
    }
    else
    {
        printf("没有找到编号为 %d 的学生信息。\n", num);
    }
}

void DelAll(void)									//删除所有的学生信息
{
PSTUDENT pstu = g_head.next, ptmp;

    int count = 0;

    if(!Question("确定要删除当前所有的学生信息吗？"))
    {
        return;
    }

    while(pstu)
    {
        ptmp = pstu;
        pstu = pstu->next;
        free(ptmp);
        ++count;
    }
	printf("删除成功！！！\n\n\n");
    printf("共删除了%d位学生信息。\n\n", count);
	system("pause");
	system("cls");
    g_head.next = NULL;

}


void SortTotal(void)	                           //对学生信息进行排序
{
	PSTUDENT p1;
	PSTUDENT p2;
	long int id;
	char name[20];
	int sex;        						   
	int age;        						    
	char major[20]; 						    
	float score[COURSE];                       
	float add;									
	float aveg;	
	int count = 0;
	int i;
	if (&g_head == NULL)
	{
		printf("没有发现数据\n");
		return ;
	}
	p1 = &g_head;
	p1 = p1->next;
	if (p1->next == NULL)
	{
		printf("排序成功\n");
	}
	p2 = p1->next;
	while (p1->next != NULL)
	{
		while (p2 != NULL)
		{
			if (p1->add > p2->add)
			{
				p2 = p2->next;
			}
			else
			{
				id = p2->num;
				strcpy(name, p2->name);
				sex = p2->sex;
				age = p2->age;
				strcpy(major, p2->major);
				for (i = 0; i < COURSE; i++)
					score[i] = p2->score[i];
				add = p2->add;
				aveg = p2->aveg;
				
				p2->num = p1->num;
				strcpy(p2->name, p1->name);
				p2->sex = p1->sex;
				p2->age = p1->age;
				strcpy(p2->major, p1->major);
				for (i = 0; i < COURSE; i++)
					p2->score[i] = p1->score[i];
				p2->add = p1->add;
				p2->aveg = p1->aveg;

				p1->num = id;
				strcpy(p1->name, name);
				p1->sex = sex;
				p1->age = age;
				strcpy(p1->major,major);
				for (i = 0; i < COURSE; i++)
					p1->score[i] = score[i];
				p1->add = add;
				p1->aveg = aveg;

				p2 = p2->next;
			}
			
		}
		p1 = p1->next;
		p2 = p1->next;
	}

	
}

void SortID(void)
{
	PSTUDENT p1;
	PSTUDENT p2;
	long int id;
	char name[20];
	int sex;
	int age;
	char major[20];
	float score[COURSE];
	float add;
	float aveg;
	int count = 0;
	int i;
	if (&g_head == NULL)
	{
		printf("没有发现数据\n");
		return;
	}
	p1 = &g_head;
	p1 = p1->next;
	if (p1->next == NULL)
	{
		printf("排序成功\n");
	}
	p2 = p1->next;
	while (p1->next != NULL)
	{
		while (p2 != NULL)
		{
			if (p1->num < p2->num)
			{
				p2 = p2->next;
			}
			else
			{
				id = p2->num;
				strcpy(name, p2->name);
				sex = p2->sex;
				age = p2->age;
				strcpy(major, p2->major);
				for (i = 0; i < COURSE; i++)
					score[i] = p2->score[i];
				add = p2->add;
				aveg = p2->aveg;

				p2->num = p1->num;
				strcpy(p2->name, p1->name);
				p2->sex = p1->sex;
				p2->age = p1->age;
				strcpy(p2->major, p1->major);
				for (i = 0; i < COURSE; i++)
					p2->score[i] = p1->score[i];
				p2->add = p1->add;
				p2->aveg = p1->aveg;

				p1->num = id;
				strcpy(p1->name, name);
				p1->sex = sex;
				p1->age = age;
				strcpy(p1->major, major);
				for (i = 0; i < COURSE; i++)
					p1->score[i] = score[i];
				p1->add = add;
				p1->aveg = aveg;

				p2 = p2->next;
			}

		}
		p1 = p1->next;
		p2 = p1->next;
	}
}

void SortScore(int n)                                  //科目排序，n为科目代码 
{
	PSTUDENT p1;
	PSTUDENT p2;
	long int id;
	char name[20];
	int sex;
	int age;
	char major[20];
	float score[COURSE];
	float add;
	float aveg;
	int count = 0;
	int i;
	if (&g_head == NULL)
	{
		printf("没有发现数据\n");
		return;
	}
	p1 = &g_head;
	p1 = p1->next;
	if (p1->next == NULL)
	{
		printf("排序成功\n");
	}
	p2 = p1->next;
	while (p1->next != NULL)
	{
		while (p2 != NULL)
		{
			if (p1->score[n] > p2->score[n])
			{
				p2 = p2->next;
			}
			else
			{
				id = p2->num;
				strcpy(name, p2->name);
				sex = p2->sex;
				age = p2->age;
				strcpy(major, p2->major);
				for (i = 0; i < COURSE; i++)
					score[i] = p2->score[i];
				add = p2->add;
				aveg = p2->aveg;

				p2->num = p1->num;
				strcpy(p2->name, p1->name);
				p2->sex = p1->sex;
				p2->age = p1->age;
				strcpy(p2->major, p1->major);
				for (i = 0; i < COURSE; i++)
					p2->score[i] = p1->score[i];
				p2->add = p1->add;
				p2->aveg = p1->aveg;

				p1->num = id;
				strcpy(p1->name, name);
				p1->sex = sex;
				p1->age = age;
				strcpy(p1->major, major);
				for (i = 0; i < COURSE; i++)
					p1->score[i] = score[i];
				p1->add = add;
				p1->aveg = aveg;

				p2 = p2->next;
			}

		}
		p1 = p1->next;
		p2 = p1->next;
	}

	//ShowAll();
	
} 

void Sort(void)
{
	system("cls");
	int running = 1;
	int n;
	while (running)
	{
		SotrUI();
		while (1 != scanf("%d", &n) || n < 1 || n > 6)
		{
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
			printf("输入错误，请重新输入:");
			while (getchar() != '\n');
		}
		//scanf("%d", &n);
		if (n == 1)
		{
			SortTotal(); ShowAll();
		}
		else if (n == 2)
		{
			SortScore(0); ShowAll();
		}
		else if (n == 3)
		{
			SortScore(1); ShowAll();
		}
		else if (n == 4)
		{
			SortScore(2); ShowAll();

		}
		else if (n == 5)
		{
			SortScore(3); ShowAll();
		}
		else
			running = 0;
		
		system("cls");								//清屏 
	}
}


void ScoreAnalysis(void)									//对总分进行分析 
{
	PSTUDENT pstu = &g_head;
	if((pstu->next)==NULL)
	{
		printf("没有发现数据，请添加数据：\n");
		AddStudent(CreateStudent());
	}
	
	float total = 0,total_ave = 0;              //总分和平均分 
	float max = 0,min = 0;                      //最大和最小 
	long int max_stu = 1,min_stu = 1;			//保存最大和最小的学生学号
	int soure_arry[3] = {810,720,540}; 
	int n = ShowStudentCount();
	int youxiu = 0,lianghao = 0,jige = 0;
	max = (pstu->next->add);
	min = (pstu->next->add);
	int i;
	while(pstu->next)
	{
		total = total + (pstu->next->add);
		if(max < (pstu->next->add))
		{
			max_stu = (pstu->next->num);
			max = (pstu->next->add);
		}
		if(min > (pstu->next->add))
		{
			min_stu = (pstu->next->num);
			min = (pstu->next->add);
		}
		if((pstu->next->add) >= 810)
			youxiu++;
		if((pstu->next->add) >= 720)
			lianghao++;	
		if((pstu->next->add) >= 540)
			jige++;
		pstu = pstu->next;
	}
	total_ave = total / n;
	int zhanyou[3] = {youxiu,lianghao,jige};
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("				\n本数据库共有 %d 个 学生的信息\n\n",n);
	printf("   			所有学生的平均分为 %.2f\n\n", total_ave);
	printf(" 			最高分为 %.2f 是学号为 %ld 的同学,最低分是 %.2f 分，是学号为 %ld 的同学\n\n",max,max_stu,min,min_stu);
	for (i = 0; i < 3; i++)
	{
		printf("			总分%d以上的有 %d 人，占总人数的 %0.2f%%\n\n", soure_arry[i],zhanyou[i],((zhanyou[i]/(float)n)*100));
	}
	AllScoreAnalysis(0,0,0,0);
	AllScoreAnalysis(1,0,1,0);
	AllScoreAnalysis(2,1,2,0);
	AllScoreAnalysis(3,1,3,0);
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	if(Question("是否要将此份报告保存到文件中？"))
	{
		FILE *fp;
		fp = fopen("baogao.txt","w");
		fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(fp,"				\n本数据库共有 %d 个 学生的信息\n\n",n);
		fprintf(fp,"   			所有学生的平均分为 %.2f\n\n", total_ave);
		fprintf(fp," 			最高分为 %.2f 是学号为 %ld 的同学,最低分是 %.2f 分，是学号为 %ld 的同学\n\n",max,max_stu,min,min_stu);
		for (i = 0; i < 3; i++)
		{
			fprintf(fp,"			总分%d以上的有 %d 人，占总人数的 %0.2f%%\n\n", soure_arry[i],zhanyou[i],((zhanyou[i]/(float)n)*100));
		}
		fclose(fp);
		AllScoreAnalysis(0,0,0,1);
		AllScoreAnalysis(1,0,1,1);
		AllScoreAnalysis(2,1,2,1);
		AllScoreAnalysis(3,1,3,1);
		fp = fopen("baogao.txt","a+");
		fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(fp,"                                                                                                           保存时间：");
		TimesTo(fp);
		fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fclose(fp);
		printf("保存成功！！！清到软件运行目录下点击 baogao.txt 查看\n");
	}
	system("pause");
	system("cls"); 
}
 
void AllScoreAnalysis(int a,int b,int k,int q)						//数学和英语和专业和选修成绩分析，参数a为课程代码，b为分数线代码，k为课程代码 ，q为输出判断
{
	PSTUDENT pstu = &g_head;
    float total = 0,total_ave = 0;              //总分和平均分 
	float max = 0,min = 0;                      //最大和最小 
	long int max_stu = 1,min_stu = 1;			//保存最大和最小的学生学号
	int soure_arry[2][3] = {{135,120,90},{270,240,180}}; 
	int n = ShowStudentCount();
	int youxiu = 0,lianghao = 0,jige = 0;
	max = (pstu->next->score[a]);
	min = (pstu->next->score[a]);
	int i;
	while(pstu->next)
	{
		total = total + (pstu->next->score[a]);
		if(max < (pstu->next->score[a]))
		{
			max_stu = (pstu->next->num);
			max = (pstu->next->score[a]);
		}
		if(min > (pstu->next->score[a]))
		{
			min_stu = (pstu->next->num);
			min = (pstu->next->score[a]);
		}
		if((pstu->next->score[a]) >= soure_arry[b][0])
			youxiu++;
		if((pstu->next->score[a]) >= soure_arry[b][1])
			lianghao++;	
		if((pstu->next->score[a]) >= soure_arry[b][2])
			jige++;
		pstu = pstu->next;
	}
	total_ave = total / n;
	int zhanyou[3] = {youxiu,lianghao,jige};
	char kecheng[4][10]={"数学","英语","专业课","选修课"};
	if(q == 0)
	{
	
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n                            		%s\n\n",kecheng[k]); 
		printf("   			所有学生的%s平均分为 %.2f\n\n",kecheng[k], total_ave);
		printf(" 			最高分为 %.2f 是学号为 %ld 的同学,最低分是 %.2f 分，是学号为 %ld 的同学\n\n",max,max_stu,min,min_stu);
		for (i = 0; i < 3; i++)
		{
			printf("			总分%d以上的有 %d 人，占总人数的 %0.2f%%\n\n", soure_arry[b][i],zhanyou[i],((zhanyou[i]/(float)n)*100));
		}
	}
	if(q == 1)
	{
		FILE *fp;
		fp = fopen("baogao.txt","a+");
		fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(fp,"\n                            		%s\n\n",kecheng[k]); 
		fprintf(fp,"   			所有学生的%s平均分为 %.2f\n\n",kecheng[k], total_ave);
		fprintf(fp," 			最高分为 %.2f 是学号为 %ld 的同学,最低分是 %.2f 分，是学号为 %ld 的同学\n\n",max,max_stu,min,min_stu);
		for (i = 0; i < 3; i++)
		{
			fprintf(fp,"			总分%d以上的有 %d 人，占总人数的 %0.2f%%\n\n", soure_arry[b][i],zhanyou[i],((zhanyou[i]/(float)n)*100));
		}
		fclose(fp);
	}
} 

void DelAllPassword(void)									//选择忘记密码后删除所有的学生信息
{
	PSTUDENT pstu = g_head.next, ptmp;
    int count = 0;
    while(pstu)
    {
        ptmp = pstu;
        pstu = pstu->next;
        free(ptmp);
        ++count;
    }
    printf("			共删除了%d位学生信息。\n", count);
    g_head.next = NULL;

} 


void FileAdRead(void)									//读取数据
{
	PSTUDENT pstu = &te;								
	PSTUDENT temp = &temps;									//临时存放数据
	int i;
	//PSTUDENT pstu = (PSTUDENT)malloc(sizeof(STUDENT));//在堆内存申请空间，存储学生信息
	DATA = fopen("Data","rb ");
	if (DATA == NULL)
	{
		DATA = fopen("Data", "wb");
		return ;
	}
	
	while(fread(temp, sizeof(STUDENT), 1, DATA) != 0)
	{
		PSTUDENT pstu = (PSTUDENT)malloc(sizeof(STUDENT));//在堆内存申请空间，存储学生信息		
		pstu->num = temp->num;
		strcpy(pstu->name, temp->name);
		pstu->sex = temp->sex;
		pstu->age = temp->age;
		strcpy(pstu->major, temp->major);
		for (i = 0; i < 4; i++)
			pstu->score[i] = temp->score[i];
		pstu->add = temp->add;
		pstu->aveg = temp->aveg;
		//printf("%.2f\n", pstu->add);
		
		AddStudent(pstu);
		pstu = pstu->next;
	
	}
	pstu->next = NULL;
	fclose(DATA);
	return ;
}						

void SaveFile(void)					//保存数据
{
	PSTUDENT pstu = &g_head;
	pstu = pstu->next;
	DATA = fopen("Data", "wb");
	while (pstu)
	{
		fwrite(pstu, sizeof(STUDENT), 1, DATA);
		pstu = pstu->next;
	}
	fclose(DATA);
}

int Times()													//获取当前时间并打印
{
	time_t t;
	struct tm * lt;
	
	time(&t);//获取Unix时间戳。
	lt = localtime(&t);//转为时间结构。
	printf("%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, (lt->tm_mon)+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果

	return 0;
}

int TimesTo(FILE *fp)									//获取当前时间到文件 
{
	time_t ti;
	struct tm * lts;
	
	time(&ti);//获取Unix时间戳。
	lts = localtime(&ti);//转为时间结构。
	fprintf(fp,"%d/%d/%d %d:%d:%d\n", lts->tm_year + 1900, (lts->tm_mon)+1, lts->tm_mday, lts->tm_hour, lts->tm_min, lts->tm_sec);//输出结果
	return 0;
}

void Save(int n)
{
	char name[6][20] = { "总分","数学","英语","专业课","选修课","学号" };
	char wenjianming[6][20] = { "TotalScore.txt","MathScore.txt","ENscore.txt","MajorScore.txt","ELEscore.txt","Score.txt" };
	FILE *fp;
	PSTUDENT pstu = &g_head;
	fp = fopen(wenjianming[n], "w");
	fprintf(fp, "\n                                                                学生成绩单(按 %s 成绩排序)\n\n",name[n]);
	fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fp,"  编号        姓名         性别     年龄          专业          数学            英语           专业课           选修课          总分          平均分\n");
	fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while (pstu->next)
	{
		fprintf(fp,"  %-10ld  ", pstu->next->num);

		fprintf(fp,"%-14s", pstu->next->name);

		fprintf(fp,"%-9s", pstu->next->sex == MAN ? "男" : "女");

		fprintf(fp,"%-6d", pstu->next->age);

		fprintf(fp,"%-20s", pstu->next->major);
		fprintf(fp,"%-15.2f %-15.2f %-15.2f %-15.2f %-15.2f %-15.2f\n\n", pstu->next->score[0], pstu->next->score[1], pstu->next->score[2], pstu->next->score[3], pstu->next->add, pstu->next->aveg);

		pstu = pstu->next;//让指针指向下一个节点
	}

	fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fp,"当前共有 %d 条信息                                                                                                    时间：", ShowStudentCount());
	TimesTo(fp);
	fprintf(fp,"--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(fp);
	printf("\n保存成功，请到程序运行目录下查看，文件名为 %s\n",wenjianming[n]);
	system("pause");							//暂停
	system("cls");								//清屏 
}

void SaveScore(void)
{
	system("cls");
	int running = 1;
	int n;
	while (running)
	{
		SaveUI();
		while (1 != scanf("%d", &n) || n < 1 || n > 7)
		{
			PlaySound(TEXT("Sound//Wrong.wav"), 0, SND_FILENAME | SND_ASYNC);
			printf("输入错误，请重新输入:");
			while (getchar() != '\n');
		}
		switch (n)
		{
			case 1:
				SortTotal(); Save(0); break;
			case 2:
				SortScore(0); Save(1); break;
			case 3:
				SortScore(1); Save(2); break;
			case 4:
				SortScore(2); Save(3); break;
			case 5:
				SortScore(3); Save(4); break;
			case 6:
				SortID(); Save(5); break;
			case 7:
				running = 0; break;
		}

	}
	system("cls");
}




