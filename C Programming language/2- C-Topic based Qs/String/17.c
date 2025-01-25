#include <stdio.h>
#include <ctype.h>
#include <string.h>

void remove_except_string_zerospace(char *str) 
{
    int write_index = 0; // Tracks where to write the next valid character
    int len = strlen(str);

    for (int i = 0; i < len; i++) 
    {
        if (isalpha(str[i])) 
        {
            str[write_index++] = str[i];
        }
    }

    // Null-terminate the modified string
    str[write_index] = '\0';
}


void remove_except_string(char *str)
{
    char pure_str [50];
    int j = 0;
    for (int i = 0; i < strlen(str) ; i++)
    {
        if (isalpha(str[i]))
        {
            pure_str[j++] = str[i];
        }
    }
    strcpy (str, pure_str);
    str[j] = '\n';
}

int main ()
{
    char str [50];
    printf("\nInput the string : ");
    fgets(str,sizeof(str),stdin);

    remove_except_string_zerospace(str);

    printf("\nAfter removing the Output String : %s ",str);

    return 0;
}