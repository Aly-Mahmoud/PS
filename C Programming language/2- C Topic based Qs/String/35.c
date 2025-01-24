#include <stdio.h>
#include <ctype.h>

int main ()
{
    char str [50];
    int ht [123] = {0};
    int i = 0;
    int count = 0;
    printf("\nInput sub-string : ");
    fgets(str,sizeof(str),stdin);

    while (str[i] != '\n')
    {
        if (isalpha (str[i]))
        {
            ht[str[i]]++;
        }

        if (ht[str[i]] == 1)
        {
            count++;
        }

        i++;
    }

    printf("\nLength of the longest substring without repeat : %d", count);

    return 0;
}