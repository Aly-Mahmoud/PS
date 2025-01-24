#include <stdio.h>
#include <string.h>
#include <ctype.h>


void inverse_capitlization (char* str)
{
    int string_length = strlen(str);

    for (int i = 0 ; i<string_length ; i++)
    {
        if ( str[i] >= 'A' && str[i] <= 'Z' )
        {
            str[i] += 32;
        }
        else if ( str[i] >= 'a' && str[i] <= 'z' )
        {
            str[i] -= 32;
        }
    }
}

void inverse_captilization2 ( char* str )
{
    int string_length = strlen(str);
    for (int i = 0 ; i<string_length ; i++)
    {
        str[i] = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
    }
}

int main()
{

    char str [50];
    printf("\nThe given sentence is   : ");
    fgets(str,sizeof(str),stdin);

    inverse_captilization2(str);

    printf("\nAfter Case changed the string  is:%s", str);

    return 0;
}



