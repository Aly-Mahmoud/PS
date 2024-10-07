#include <stdio.h>
#include <stdlib.h>

int factorial (int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else 
        return n*factorial(n-1);
}

int main ()
{

    int n;
    scanf("%d", &n);

    printf("%d",factorial(n));

    getchar();
    getchar();
    return 0;
}