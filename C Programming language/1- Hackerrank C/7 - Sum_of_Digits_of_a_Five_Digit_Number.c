#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    int n= 12345;
    // scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int _5th= n%10;
    int _4th= (n%100)/10;
    int _3rd= (n%1000)/100;
    int _2nd= (n%10000)/1000;
    int _1st= n/10000;
    
    n = _1st + _2nd + _3rd + _4th + _5th;
    printf("%d", n);
    
    return 0;
}