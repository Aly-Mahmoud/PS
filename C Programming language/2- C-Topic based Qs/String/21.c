#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main ()
{
    char str [50];
    printf("\nInput a string in lowercase : ");
    fgets(str,sizeof(str),stdin);
    int i = 0;
    int string_length =  strlen(str);
    printf("\nHere is the above string in UPPERCASE :");
    for (int i = 0 ; i < string_length ; i++)
    {
        if (islower(str[i]))
            printf("%c", str[i]-32);
        else if (isspace(str[i]))
             printf(" ");
    }

    return 0;
}