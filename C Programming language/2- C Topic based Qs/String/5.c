#include <stdio.h>

int main ()
{
    char str [50];
    int counter = 0;
    int w_counter = 0;


    fgets(str, sizeof str, stdin);

    while (str[counter] != '\0' && str[counter] != '\n')
    {
        if (str[counter] == ' ' && str[counter-1] != ' ')
        {
            w_counter++;
        }
        counter++;
    }

    printf("the word counter is: %d", w_counter+1);

    return 0;
}