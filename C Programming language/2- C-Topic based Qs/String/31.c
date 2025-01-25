#include <stdio.h>

int main ()
{
    char str [50];
    printf("\nInput a string : ");
    fgets(str,sizeof(str),stdin);
    int i = 0;

    while (str[i] != '\n')
    {
        if (str[i] == ' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c",str[i]);
        }
        i++;
    }
    return 0;
}
