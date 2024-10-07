#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) 
{
    int start;
    int next;
    
    int MAX_AND =0;
    int MAX_OR  =0;
    int MAX_XOR =0;

    for (start = 1; start < n+1 ;start++)
    {
        for (next=start+1; next < n+1 ; next++)
        {
            int AND_V = start & next; if (( AND_V > MAX_AND )&&( AND_V < k )) {MAX_AND = AND_V;}
            int OR_V  = start | next; if ((  OR_V > MAX_OR  )&&( OR_V  < k )) {MAX_OR  = OR_V;}
            int XOR_V = start ^ next; if (( XOR_V > MAX_XOR )&&( XOR_V < k )) {MAX_XOR = XOR_V;}
        }
    }
    printf("%d\n",MAX_AND);
    printf("%d\n",MAX_OR );
    printf("%d\n",MAX_XOR);
}

int main() {
    // int n, k;
    int n = 5;
    int k = 4;
    // scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
