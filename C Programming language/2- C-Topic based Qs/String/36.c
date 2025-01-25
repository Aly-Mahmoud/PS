#include <stdio.h>

int main ()
{
    char str [50];
    int i = 0;
    int bracket [4] = {0};  // ()  {}  []  <>
    int indicator = 0;
    printf("\nInput a string : ");
    fgets (str, sizeof(str),stdin);

    while (str[i] != '\n')
    {
        if (str[i] == '(')
        {
            bracket[0]++;
        }
        else if (str[i] == ')')
        {
            bracket[0]--;
        }
        else if (str[i] == '{')
        {
            bracket[1]++;
        }
        else if (str[i] == '}')
        {
            bracket[1]--;
        }
        else if (str[i] == '[')
        {
            bracket[2]++;
        }
        else if (str[i] == ']')
        {
            bracket[2]--;
        }
        else if (str[i] == '<')
        {
            bracket[3]++;
        }
        else if (str[i] == '>')
        {
            bracket[3]--;
        }
        i++;
    }

    for (int i = 0 ; i< 4 ; i++)
    {
        if (bracket[i] != 0)
        {
            indicator = 1;
            break;
        }
    }

    if (indicator)
    {
        printf("\nbrackets are not valid ");
    }   
    else
    {
        printf("\nbrackets are valid ");
    }

    return 0;
}