#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[100];
    int i, len;
    scanf("%s", str);
    len = strlen(str);
    for (i = len - 1; i >= 0; i--)
        printf("%c", str[i]);
    return 0;
}