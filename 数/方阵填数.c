#include <stdio.h>


int map[20][20] = {0};
void fill_map(int t, int l, int s)
{
    
    for (int i = l + 1; i <= s; i++)
        map[i][s] = t++;
    for (int i = s - 1; i >= l + 1; i--)
        map[s][i] = t++;
    for (int i = s - 1; i >= l + 1; i--)
        map[i][l + 1] = t++;
    for (int i = l + 2; i <= s - 1; i++)
        map[l + 1][i] = t++;
    if (s >= 0)
        fill_map(t, l + 1, s - 1);
}

void print_map1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            printf("%d ", map[i][j]);
        printf("%d\n", map[i][n]);
    }
}

int main(void)
{
    
    int n;
    scanf("%d", &n);
    fill_map(1, 0, n);
    print_map1(n);
    return 0;
}