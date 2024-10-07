#include <stdlib.h>
#include <stdio.h>

int iter = 4;
int _2power(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return 2 * _2power(num-1);
    }
}

void dec_2_bin (int num)
{
    printf("%d", ((num&_2power(iter))>>iter));
    iter--;
    if(iter >= 0)
    {
        dec_2_bin(num);
    }
    else
        return;
}

int main ()
{

    int n;
    scanf("%d", &n);

    dec_2_bin(n);
    getchar();
    getchar();

    return 0;
} 