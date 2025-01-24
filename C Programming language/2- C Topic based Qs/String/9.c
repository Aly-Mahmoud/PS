#include <stdio.h>

int main ()
{
    char str [50];
    fgets(str,sizeof str, stdin);
    
    int counter   =0;
    int v_counter =0;
    int c_counter =0;

    while ( str[counter] != '\n')
    {
        if( (str[counter] >= 65 && str[counter] <= 90) || (str[counter] >= 97 && str[counter] <= 122) )
        {
            if ( str[counter] == 'a' || str[counter] == 'e' || str[counter] == 'i' || str[counter] == 'o' || str[counter] == 'u' || str[counter] == 'A' || str[counter] == 'E' || str[counter] == 'I' || str[counter] == 'O' || str[counter] == 'U')
                v_counter++;
            else
                c_counter++;    
        }
        counter++;
    }

    printf("The total number of vowel in the string is : %d\n", v_counter );
    printf("The total number of consonant in the string is : %d\n", c_counter );

    return 0;
}
