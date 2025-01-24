#include <stdio.h>
#include <string.h>

int main ()
{

    char str1 [] = "Hello";
    str1[0] = 'h';
    char str2 [] = {'h','e','L','L','o','\0'};
    char* ptr1 = "Hello,World";
    
    char str3 [] = str1;
    char str4 [] = str2;
    char* ptr2 = *ptr1;


    printf ("\n%s", str1);
    printf ("\n%s", str3);
    printf ("\n%s", str2);
    printf ("\n%s", str4);
    printf ("\n%s", ptr1);
    printf ("\n%s", ptr2);

    printf("\n%d",sizeof (str1));
    printf("\n%d", strlen(str1));
    printf("\n%d", sizeof (ptr1));

    return 0;
}