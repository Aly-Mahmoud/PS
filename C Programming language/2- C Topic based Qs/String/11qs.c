#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_char (const void *a, const void *b)
{
    return (* (char*) a - * ( char*) b);
}

int main ()
{

    char str [50];
    fgets (str, sizeof(str), stdin);

    qsort (str, strlen(str), sizeof(char) ,compare_char);

    printf("The sorted string :%s",str );

    return 0;
}