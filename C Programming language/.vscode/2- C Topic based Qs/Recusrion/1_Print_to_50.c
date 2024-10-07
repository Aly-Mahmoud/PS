#include <stdio.h>
#include <stdlib.h>

/*Print from n to 50 using recursion*/

int print_increment(int n)
{
    if (n == 51) 
    {
        return 0;
    }
    else    
    {
        printf("%d ", n );
        return print_increment(n+1);
    }
}
int main ()
{
    int n;
    scanf("%d", &n );
    print_increment(n);
    getchar();
    getchar();
    return 0;
}