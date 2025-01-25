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

    if (*p_a > *p_b)
    {
        printf("the max number is : %d", *p_a);
    }
    else if (*p_b > *p_a)
    {
        printf("the max number is : %d", *p_b);
    }
    else 
    {
        printf("the two numbers are equal : %d", *p_b);
    }

    return 0;
}