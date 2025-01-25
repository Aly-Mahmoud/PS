#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char input ;
    printf("\nPlease enter your char : ");
    scanf("%c",&input);

    if (islower(input))
    {
        printf("\nThe entered letter is a lowercase letter.");
    }
    else 
    {
        printf("\nThe entered letter is not a lowercase letter.");
    }


    return 0;
}