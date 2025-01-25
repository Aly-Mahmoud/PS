#include <stdio.h>

/*
int main()
{
    char string [50];
    fgets(string, sizeof string, stdin);

    int counter =0;

    while (string[counter] != '\0' && string[counter] != '\n')
    {
        counter++;
    }

    while (counter >= 0)
    {
        printf("%c ", string[counter]);
        counter--;
    }
    return 0;
}
*/

#include <string.h>

int main ()
{
    char str [50];

    fgets(str,sizeof str, stdin);

    int size = strlen(str);

    while (size >= 0)
    {
        printf("%c ", str[size] );
        size --;
    }
    
    return 0;
}