#include <stdio.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char word1[550], char word2[550])
{
    int i, j;
    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
    int dp[word1Length + 1][word2Length + 1];
    for (i = 0; i <= word1Length; i++)
    {
        dp[i][0] = i;
    }

    for (j = 0; j <= word2Length; j++)
    {
        dp[0][j] = j;
    }

    for (i = 1; i <= word1Length; i++)
    {
        for (j = 1; j <= word2Length; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }
    return dp[word1Length][word2Length];
}

int main(void)
{
    char word1[550], word2[550];
    scanf("%s", word1);
    scanf("%s", word2);
    printf("%d\n", minDistance(word1, word2));
    return 0;
}