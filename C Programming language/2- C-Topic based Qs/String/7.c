#include <stdio.h>

#define str_len 50

int main()
{
    char str [str_len];

    printf("Please insert your text : ");

    fgets(str,sizeof str, stdin);

    int counter=0;

    int letter_counter=0;
    int digital_counter=0;
    int special_counter=0;

    while ( str[counter] != '\n' )
    {
        if( (str[counter] >= 65 && str[counter] <= 90) || (str[counter] >= 97 && str[counter] <= 122) )
        {
            letter_counter++;
        }
        else if ( str[counter] >= 48 && str[counter] <= 57)
        {
            digital_counter++;
        }
        else
        {
            special_counter++;
        }

        counter++;
    }

    printf("Number of Alphabets in the string is : %d\n", letter_counter );
    printf("Number of Digits in the string is : %d \n", digital_counter);
    printf("Number of Special characters in the string is : %d\n", special_counter);

    return 0;
}