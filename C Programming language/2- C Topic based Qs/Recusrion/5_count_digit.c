#include <stdio.h>
#include <stdlib.h>

int counter = 1;
 
int count (int num , int iter)
{
    if ( (num-iter*10) >= 0)
    {
        counter++;
        count(num,iter*10);
    }
    else
        return counter;
}

int main ()
{
    int num;

    scanf("%d" , &num);

    printf("%d" , count(num , 1));

    return 0;
}