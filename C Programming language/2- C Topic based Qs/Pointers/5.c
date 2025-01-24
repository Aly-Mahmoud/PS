#include <stdio.h>

int sum (int *p1, int *p2)
{
    int sum_2 = *p1 + *p2;
    return sum_2;
}

int main ()
{
    int a ;
    int b ;

    printf("\nInput the first number   : ");
    scanf("%d",&a);
    printf("\nInput the secound number : ");
    scanf("%d",&b);

    int sum_2 = sum (&a ,&b);

    printf("\nThe sum of the entered numbers is : %d", sum_2);

    return 0;
}