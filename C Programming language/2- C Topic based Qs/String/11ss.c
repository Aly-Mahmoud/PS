#include <stdio.h>
#include <string.h>

void swap_char (char* a, char* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void selection_sort (char* data, int size)
{
    int i = 0;
    int j = 0;
    
    for (i=0 ; i<size-1 ; i++)
    {
        for (j=i+1; j<size ; j++)
        {
            if (data[i] > data[j])
            {
                swap_char(&data[i],&data[j]);
            }
        }
    }
}

int main ()
{
    char str [50];

    fgets(str, sizeof str, stdin);

    selection_sort( str , strlen(str) );

    printf("the sorted string is : %s", str);

    return 0;
}