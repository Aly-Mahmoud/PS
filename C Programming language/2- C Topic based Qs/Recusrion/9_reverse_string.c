#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string( char* string , int str_legth )
{
    if (str_legth > 0)
    {
        printf( "%c" , string[str_legth-1] );
        reverse_string( string , str_legth-1 );
    }
    else
    {
        return;
    }
}

int main ()
{
    int str_length ;
    printf("String size: ");
    scanf( "%d" , &str_length );
    char* string = (char*)malloc(sizeof(char)*(str_length+1));
    printf("String :");
    scanf( "%s" , string );

    reverse_string( string , str_length );

    free(string);

    return 0;
}