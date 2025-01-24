#include <stdio.h>
#include <ctype.h>

int main ()
{
    char input;
    printf("\nInput a character : ");
    scanf("%c",&input);

    if (isdigit(input))
    {
        printf("The entered character is a digit.");
    }
    else 
    {
        printf("The entered character is not a digit.");
    }

    return 0;
}