#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str [50];
    char special_char;

    printf("\nInput a string : ");
    fgets(str,sizeof(str),stdin);

    printf("\nInput special character : ");
    scanf("%c",&special_char);

    int length = strlen(str);

    for (int i = 0 ; i<length ; i++)
    {
        if (isspace(str[i]))
        {
            printf("%c",special_char);
        }
        else 
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}