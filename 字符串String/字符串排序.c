#include<stdio.h>
#include<string.h>

void sort(char a[3][100],int n);

int main(void)
{
    char str[3][100];
    int i = 0;
    for(i = 0; i < 3; i++)
        scanf("%s",&str[i]);

    sort(str,3);
    printf("%s\n",str[0]);
    printf("%s\n",str[1]);
    printf("%s",str[2]);
    return 0;
}

void sort(char a[3][100], int n)
{
    int i, j;
    char temp[100];
    for (i = 0;i < n-1;i ++)
	{
		for (j = 0;j < n-1-i;j++)
		{
			if (strcmp(a[j],a[j+1]) > 0)
			{
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
			}
		}
	}

}
