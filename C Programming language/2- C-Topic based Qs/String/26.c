#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str [50];
    int count = 0;
    printf("\nEnter your text : ");
    fgets(str,sizeof(str),stdin);

    int length = strlen(str);

    for (int i = 0; i<length ; i++)
    {
        if (ispunct(str[i]))
        {
            count++;
        }
    }

    printf("\nThe punctuation characters exists in the string is : %d", count);

    return 0;
}