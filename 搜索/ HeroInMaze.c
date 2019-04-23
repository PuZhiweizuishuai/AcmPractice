#include <stdio.h>

int Maze(char maze[25][25], int n, int m)
{
    
    return 1;
}

int main(void)
{
    int i, j;
    int N, M, T;
    char maze[25][25];

    while (1)
    {
        scanf("%d%d%d", &N, &M, &T);
        if(N == 0 &&  M == 0 && T == 0)
            break;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                scanf("%c", &maze[i][j]);
            }
        }
    }

    return 0;
}