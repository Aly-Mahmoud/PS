#include <stdio.h>
#include <string.h>

int main ()
{
    char str [50];
    char freq_char ;
    int counter = 0;
    printf("\nInput the string : ");
    fgets(str,sizeof(str),stdin);

    printf("\nInput the character to find frequency: ");
    scanf("%c",&freq_char);

    int string_length = strlen(str);
    for (int i = 0 ; i < string_length ; i++)
    {
        if (str[i] == freq_char)
        {
            counter++;
        }
    }

    printf("The frequency of '%c' is : %d", freq_char, counter);

    return 0;
}