#include <stdio.h>
#include <string.h>

void subtract_substring ( char* original , char* sub_string ,  int start_index , int size)
{
    for (int j=0 ; j<=size ; j++)
    {
        sub_string[j] = original[start_index+j];
    }
    sub_string[size] = '\0';
}


int the_counter (char* str)
{
    char test_the [4];
    const char the[] = {"the"};
    int count = 0;

    for (int i = 0 ; i < strlen(str) - 3 ; i++)
    {
        if (str[i] == 't')
        {
            subtract_substring ( str , test_the , i , 3 );
            if (strcmp ( test_the , the ) == 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main ()
{
    char str [50];
    printf("\nInput the string : ");
    fgets(str,sizeof(str),stdin);

    printf("\nthe frequency of the word 'the' is :  %d", the_counter(str));
}