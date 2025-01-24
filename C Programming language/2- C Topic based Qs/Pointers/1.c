#include <stdio.h>

int main ()
{
    int m = 10;
    int n;
    int o;

    int *z = &m;

    printf("\nz stores the address of m  = 0x%p",z);
    printf("\n*z stores the value of m = %d",*z);
    printf("\n&m is the address of m = 0x%x", &m);
    printf("\n&n stores the address of n = 0x%x", &n);
    printf("\n&o stores the address of o = 0x%x", &o);
    printf("\n&z stores the address of z = 0x%x", &z);


    return 0;
}