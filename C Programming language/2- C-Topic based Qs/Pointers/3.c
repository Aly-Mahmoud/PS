#include <stdio.h>

int main ()
{
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    int *p_m = &m;
    float *p_fx = &fx;
    char *p_cht = &cht;


    printf("\nm = %d ", m);
    printf("\nfx = %f" , fx);
    printf("\ncht = %c", cht);
    printf("\n");
    printf("\nusing & operator :");
    printf("\n--------------------");
    printf("\naddress of m = 0x%p", &m);
    printf("\naddress of fx = 0x%p", &fx);
    printf("\naddress of cht = 0x%p", &cht);
    printf("\n");
    printf("\nUsing & and * operator :");
    printf("\n--------------------");
    printf("\nvalue at address of m = %d", *(&m));
    printf("\nvalue address of fx = %f", *(&fx));
    printf("\nvalue address of cht = %c", *(&cht));
    printf("\n");
    printf("\nUsing only pointer variable :");
    printf("\n--------------------");
    printf("\naddress of m = 0x%p", p_m);
    printf("\naddress of fx = 0x%p", p_fx);
    printf("\naddress of cht = 0x%p", p_cht);
    printf("\n");
    printf("\nUsing only pointer operator :");
    printf("\nvalue at address of m = %d", *p_m);
    printf("\nvalue at address of fx = %f", *p_fx);
    printf("\nvalue at address of cht = %c", *p_cht);


    return 0;
}