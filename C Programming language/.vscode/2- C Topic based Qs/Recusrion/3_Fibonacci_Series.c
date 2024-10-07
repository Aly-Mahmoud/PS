#include <stdio.h>
#include <stdlib.h>

int Fibonacci_Series ( int n )
{
    while (n>= 1)
    {
        if ( n == 0 )
        {
            return 0;
        }
        else if ( n == 1 )
        {
            return 1;
        }
        else 
        {
            return Fibonacci_Series(n-1)+Fibonacci_Series(n-2);
        }
    }
}
int main ()
{
    int n ;
    scanf("%d",&n);
    int i;
    for (i = 0 ; i < n ;i++)
    {
        printf("%d",Fibonacci_Series(i));
    }
    return 0;
}