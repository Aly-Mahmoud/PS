#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str [50];
    char input = 0;
    printf("\nInput a character : ");
    scanf("%c", &input);

    if (isxdigit(input))
    {
        printf("\nThe entered character is a hexadecimal digit.");
    }
    else
    {
        if (isalpha(input))
        {
            if ((input >= 'A' && input<= 'F' ) || (input >= 'a' && input <= 'f'))
            {
                printf("\nThe entered character is a hexadecimal digit.");
            }
            else
            {
                printf("\nThe entered character is not a hexadecimal digit.");
            }
        }
        else 
        {
            printf("\nThe entered character is not a hexadecimal digit.");
        }
    }

    return 0;
}