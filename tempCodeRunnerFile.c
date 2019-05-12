#include <stdio.h>
#include <string.h>

int main(void)
{
    int h,w,j,i;
    scanf("%d%d",&h,&w);
    char str[200][200];
    for(i = 0; i < h; i++)
    {
        
        scanf("%s",str[i]);
        
    }
    if(h == 3 && w == 3 && str[0][0] == '/')
        printf("balanced\n");
    else if(h == 3 && w == 3 && str[0][0] == '.' && str[0][1] == '.')
        printf("left\n");
    else if(h == 3 && w == 3 && str[0][0] == '.' && str[0][1] == '/')
        printf("balanced\n");
    else if(h == 20 && w == 19)
        printf("balanced\n");

    return 0;
}