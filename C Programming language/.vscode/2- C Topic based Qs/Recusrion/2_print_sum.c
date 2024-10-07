#include <stdio.h>
#include <stdlib.h>

/*Write a program in C to calculate the sum of numbers from 1 to n using recursion.*/

int print_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else 
    {
        return n + print_sum(n-1);
    }
}

int main ()
{
    int n;
    scanf("%d", &n);
    printf("%d", print_sum(n));
    return 0;
}