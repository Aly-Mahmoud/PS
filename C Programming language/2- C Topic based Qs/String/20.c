#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main ()
{
    char str [50];

    int big_str_size = 0;
    int big_str_index = 0;

    int small_str_size = 50;
    int small_str_index = 0;


    int prev_space = -1;
    int current_space = 0;
    int word_size = 0;

    printf("\nInput the string : ");
    fgets(str,sizeof(str),stdin);
    int size = strlen(str);

    for ( int i = 0; i<size ; i++)
    {
        if (isspace(str[i]) || str[i] == '\0')
        {
            current_space = i;
            if (prev_space == -1) 
            {
                word_size = current_space;  
            } 
            else
            {
                word_size = current_space - prev_space - 1;
            }
            if (word_size > big_str_size)
            {
                big_str_size = word_size;
                big_str_index = prev_space+1;
            }
            if (word_size < small_str_size && word_size > 0)
            {
                small_str_size = word_size;
                small_str_index = prev_space+1;
            }
            prev_space = current_space;
        }
    }

    printf("The largest word is: ");
    for (int i = big_str_index; i < big_str_index + big_str_size; i++) 
    {
        printf("%c", str[i]);
    }

    printf("\nAnd the smallest word is: ");
    for (int i = small_str_index; i < small_str_index + small_str_size; i++) 
    {
        printf("%c", str[i]);
    }

    return 0;

}