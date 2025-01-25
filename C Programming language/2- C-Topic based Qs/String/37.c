#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
I am not sure that this is the answer to this question, 
i did not fully get it
*/

int main ()
{
    char str_1 [50];
    char str_2 [50];   

    int number_1 = 0;
    int number_2 = 0;
    int j = 1;

    printf("\nOriginal number1 : ");
    fgets(str_1,sizeof(str_1),stdin);
    printf("\nOriginal number2 : ");
    fgets(str_2,sizeof(str_2),stdin);

    int str_1_size = strlen(str_1);
    int str_2_size = strlen(str_2);

    for ( int i = str_1_size-2 ; i >= 0 ; i--)
    {
        if (isdigit(str_1[i]))
        {
            number_1 += (str_1[i]-48) * j;
            j*=10;
        }
    }

    j = 1;

    for ( int i = str_2_size-2 ; i >= 0 ; i-- )
    {
        if (isdigit(str_2[i]))
        {
            number_2 += (str_2[i]-48) * j;
            j*=10;
        }
    }  

    int result = number_1 * number_2;

    printf("\nthe result : %d", result);

    return 0;
}