#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arrayStringsAreEqual(const char** word1, int word1Size, const char** word2, int word2Size) 
{
    const char* letter1 = *word1;
    const char* letter2 = *word2;

    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;

    while ( i < word1Size && m < word2Size )
    {
        if (word1[i][j] == '\0' || word2[m][n] == '\0' )
        {
            if (word1[i][j] == '\0')
            {
                i++;
                j=0;
            }
            if (word2[m][n] == '\0')
            {
                m++;
                n=0;
            }
            continue;
        }

        if (word1[i][j] != word2[m][n])
        {
            return 0;
        }
        j++;
        n++;
    }
    return (i==word1Size && m==word2Size);
}

int main()
{
    const char* word1[] = {"ab","c"};
    const char* word2[] = {"a","bc"};
    printf("%d" , arrayStringsAreEqual(word1,2,word2,2));
    return 0;
}
