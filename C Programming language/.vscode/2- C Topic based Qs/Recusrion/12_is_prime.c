#include <stdio.h>
#include <stdlib.h>

int divisor = 2;

int is_prime(int num)
{
    if ( num == divisor )
    {
        return 1;
    }
    else if( num%divisor == 0 )
    {
        return 0;
    }
    else
    {
        divisor++;
        is_prime(num);
    }

}

int main ()
{
    int num;
    scanf("%d" , &num);

    if (is_prime(num))
    {
        printf("It is Prime");
    }
    else 
    {
        printf("It is not Prime");
    }

    getchar();
    getchar();
    return 0;
}