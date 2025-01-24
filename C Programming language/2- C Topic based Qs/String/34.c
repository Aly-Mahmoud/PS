#include <stdio.h>
#include <string.h>

int main ()
{
    char str [50];
    int i = 0;

    printf("\nInput a sentence : ");
    fgets(str,sizeof(str),stdin);

    printf("\nAfter converting vowels into upper case the sentence becomes : ");
    while (str[i] != '\n')
    {
        if (str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u')
        {
            str[i]-=32;
        }
        printf("%c", str[i]);
        i++;
    }


    return 0;
}