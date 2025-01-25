#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str [50];
    int str_len;
    int ht [123]= {0};

    printf("Input a string: ");
    fgets(str,sizeof(str),stdin);

    str_len = strlen(str);

    for (int i = 0 ; i<str_len ; i++)
    {
        if (isalpha(str[i]))
        {
            ht[str[i]]++;
        }
    }

    for (int i = 'A' ; i <= 'z' ; i++)
    {
        if (ht[i] > 0)
        {
            printf("\n%c         %d",i,ht[i]);
        }
    }



    return 0;
}