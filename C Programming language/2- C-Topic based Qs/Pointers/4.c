#include <stdio.h>

int main ()
{
    int a ;
    int b ;

    printf("\nInput the first number   : ");
    scanf("%d",&a);
    printf("\nInput the secound number : ");
    scanf("%d",&b);

    int *p_a = &a;
    int *p_b = &b;

    int sum = *p_a + *p_b;

    printf("\nThe sum of the entered numbers is : %d", sum);


    return 0;
}