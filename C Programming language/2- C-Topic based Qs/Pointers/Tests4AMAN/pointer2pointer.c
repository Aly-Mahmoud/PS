
/*
Problem:
Write a C program that swaps two integer values using pointer to pointer (i.e., a pointer pointing to another pointer).

Instructions:
Declare two integer variables, a and b, and initialize them with any values.
Use pointer to pointer to swap the values of a and b.
Print the values of a and b before and after the swap to verify the result.
*/

#include <stdio.h>

void swap ( int ** pa , int  ** pb)
{
    int temp;
    temp = *(*pa);
    *(*pa) = *(*pb);
    *(*pb) = temp;
}

int main ()
{

    int a = 5;
    int b = 6;

    int* pa = &a;
    int* pb = &b;

    int** ppa = &pa;
    int** ppb = &pb;

    swap ( ppa , ppb);

    printf("%d %d",a,b);


    return 0;
}