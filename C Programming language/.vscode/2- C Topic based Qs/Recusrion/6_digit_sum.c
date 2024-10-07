#include <stdio.h>
#include <stdlib.h>

digit_sum(int num)
{
    if( num == 0)
        return 0;

    return ((num%10)+digit_sum(num/10));   
}

int main ()
{
    int n;
    scanf("%d", &n);

    digit_sum(n);

    getchar();
    getchar();
    return 0;
}