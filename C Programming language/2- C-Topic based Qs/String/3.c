#include <stdio.h>
#include <string.h>

int main()
{
    char string [50];
    int n=0;

    fgets(string, sizeof string, stdin);

    while (string[n] != '\0' && string[n] != '\0')
    {
        printf("%c " , string[n]);
        n++;
    }

}