#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str [50];
    char input;
    printf("\nInput a character : ");
    scanf("%c",&input);

    if (isupper(input))
    {
        printf("\nThe entered letter is an UPPERCASE letter.");
    }
    else 
    {
        printf("\nThe entered letter is not an UPPERCASE letter.");
    }
    
    return 0;

}