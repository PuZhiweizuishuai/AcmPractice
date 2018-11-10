#include <stdio.h>
#define N 100
/**
 * 读入一个浮点数值，将其转化为金额的中文大写形式。
*/
void BigChineseMoney(char num[]);

/**
* 判断 x 位后数组是否全部为 0，全为 0 返回 1， 不然返回 0
* n 数组大小或大于 x 的一个数
* x x位后
*/
int Zeor(int a[], int n, int x);

int main(void)
{
	char s[N];
	while (scanf("%s",s) != EOF)
	{
		BigChineseMoney(s);
	}
	
	return 0;
}

void BigChineseMoney(char num[])
{
	char money[12][10] = { {"元"}, {"拾"}, {"佰"}, {"仟"}, {"万"},{"拾"}, {"佰"}, {"仟"} ,{"亿"},{"拾"}, {"佰"}, {"仟"} };
	char fen[2][10] = { {"角"}, {"分"} };

	char number[11][10] = { {"零"}, {"壹"}, {"贰"}, {"叁"}, {"肆"}, {"伍"}, {"陆"}, {"柒"}, {"捌"}, {"玖"}, {"拾"} };
	// 保存数字化后的结果
	int RMB[N];
	// countLeft小数点前的位数
	// countRight 小数点后位数
	int countLeft = 0, countRight = -1, flag = 1, i = 0, j = 0;
	while (1)
	{
		if (num[i] == '.') flag = 0;
		if (num[i] == '\0') break;
		if (flag == 1) countLeft++;
		else countRight++;
		i++;
	}
	for (i = 0; i < countLeft; i++)
		RMB[i] = (int)(num[i] - '0');

	// yiFlag通过判断对大于9位数的单位亿的添加
	// wanFlag通过判断对大于9位数的单位万的添加
	int yiFlag = 0, wanFlag = 0;
	for (i = 0, j = countLeft; i < countLeft; i++, j--)
	{
		if (RMB[i] == 0)
		{
			// 如果前一个数为零则忽略单位与数字输出
			if (RMB[i - 1] == 0 || i == countLeft - 1)
				;
			// 如果从RMB[i]这个数后所有数都为 0 ，则不输出 零，反之输出 0
			else if (Zeor(RMB, countLeft, i) == 0)
				printf("%s", number[RMB[i]]);
			
			// 输出元
			if (i == countLeft - 1)
				printf("%s", money[RMB[i]]);
		}
		else
		{
			// 对拾元，十万，十亿的特殊处理，消去本应输出的 壹
			if (i == 0 && (j == 10 || j == 6 || j == 2) && RMB[0] == 1)
			{
				printf("%s", money[j - 1]);
				if (RMB[1] == 0 && j <= 6 && j > 2)
				{
					printf("万");
					continue;
				}
				else if (RMB[1] == 0 && j >= 9)
					printf("亿");
				continue;
			}
			// 正常输出
			printf("%s", number[RMB[i]]);
			printf("%s", money[j - 1]);
			// 当万位和亿位为0时，补全十万以上数的万和亿的单位
			if (RMB[countLeft - 9] == 0 && j >= 9 && yiFlag == 0 && i == countLeft - 10)
			{
				yiFlag = 1;
				printf("亿  i=%d  ",i);
			}
			else if (RMB[countLeft - 5] == 0 && j >= 5 && j < 9 && wanFlag == 0 && i == countLeft - 6)
			{
				wanFlag = 1;
				printf("万");
			}
			
		}
	}
	if (countRight == -1)
		printf("整");
	else
	{
		for (i = 0, j = countRight; i < countRight; i++, j--)
		{
			if ((int)(num[countLeft + 1 + i] - '0') == 0)
				continue;
			printf("%s", number[(int)(num[countLeft + 1 + i] - '0')]);
			printf("%s", fen[i]);
		}
	}
	printf("\n");
}

int Zeor(int a[], int n, int x)
{
	int i;
	for (i = x; i < n; i++)
	{
		if (a[i] != 0)
			return 0;
	}
	return 1;
}