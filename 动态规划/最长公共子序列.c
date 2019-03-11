#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAX 3010
char wordA[MAX];
char wordB[MAX];
int dp[MAX][MAX];
int main(void)
{
    int i, j;
    while (scanf("%s %s", wordA, wordB) != EOF)
    {
        int lena = strlen(wordA);
        int lenb = strlen(wordB);
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (i = 0; i <= lena; i++)
        {
            for (j = 0; j <= lenb; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (wordA[i-1] == wordB[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //printf("%d   ", dp[i][j]);
            }
        }
        printf("%d\n", dp[lena][lenb]);

    }

    return 0;
}