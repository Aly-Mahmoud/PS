#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap (char** a, char** b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char** data, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if ( strcmp (data[j] , data[j+1]) > 0 ) 
            {
                swap(&data[j], &data[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main()
{
    int string_counter = 0;

    printf("\n Input number of strings :");
    scanf("%d",&string_counter);

    char **strings = (char**) malloc( string_counter*sizeof(char*) );

    for(int i=0; i<string_counter; i++)
    {
        strings[i] =(char*)malloc(50 * sizeof(char));
        printf("\n Input number %d of strings :", i+1);
        scanf ("%49s", strings[i]);
    }

    bubbleSort(strings, string_counter);

    printf("The Sorted String are :\n");

    for(int i = 0; i < string_counter ; i++)
    {
            printf("%s\n", strings[i]);
            free(strings[i]);
    }
    free (strings);
    return 0;
}