#include <stdio.h>

int main ()
{
    int m = 29;

    printf("\n--------------------------------------");  
    printf("\nAddress of m :                    0x%p", &m);
    printf("\nValue of m   :                      %d", m);
    printf("\n--------------------------------------");
    
    int *ab = &m;

    printf("\nAddress of pointer ab :           0x%p", &ab);
    printf("\nAddress pointer ab points to is : 0x%p", ab);
    printf("\nContent of pointer ab :             %d", *ab);
    printf("\n--------------------------------------");
    printf("\nAddress of m :                    0x%p", &m);
    printf("\nValue of m   :                      %d", m);

    m = 34;

    printf("\n---------------------------------------");
    printf("\nAddress of pointer ab :            0x%p", &ab);
    printf("\nAddress pointer ab points to is :  0x%p", ab);
    printf("\nContent of pointer ab :              %d", *ab);
    printf("\n---------------------------------------");

    *ab = 7;

    printf("\n----------------------------------------------");
    printf("\nAddress of m :                     0x%p", &m);
    printf("\nValue of m :                         %d", m);
    printf("\n-----------------------------------------------");

    return 0;
}