#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char str[] = " The quick brown fox \n jumps over the \n lazy dog. \n"; // String to process

    int length = strlen(str);
    for (int i = 0 ; i < length ; i++)
    {
        if (isprint(str[i]))
        {
            printf("%c",str[i]);
        }
        else 
        {
            break;
        }
    }
    return 0;

}