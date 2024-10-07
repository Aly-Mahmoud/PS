#include <stdio.h>
#include <stdlib.h>

int smallest;
int largest;
int GCD;

int find_GCD(int num1 , int num2 , int iter)
{
    if (iter == 1)
    {
        if(num1 > num2)
        {
            smallest = num2;
            largest = num1;
        }
        else if (num2> num1)
        {
            smallest = num1;
            largest  = num2;
        }
    }

    if ( (num1%iter == 0)  && (num2%iter == 0))
    {
        GCD = iter;
        if (iter == smallest)
        {
            return GCD;
        }
        ++iter;
    }
    else
    {
        ++iter;
    }

    find_GCD(num1,num2, iter);
}

int main ()
{
    int num1;
    int num2;

    printf("Enter num 1: ");
    scanf("%d", &num1 );
    printf("Enter num 2: ");
    scanf("%d", &num2 );

    printf("the GCD is: ");
    printf("%d",find_GCD(num1, num2 , 1));

    getchar();
    getchar();
    return 0;
}