#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*The problem with this code is that it only works if n = 5*/

int main() 
{

    int n = 5;
    //scanf("%d", &n);
      
    int matrix = (2*n)-1;

    for (int line_iter = 0; line_iter < matrix; line_iter++)
    {
        for(int digit_iter = 0; digit_iter < matrix; digit_iter++)
        {
            int p_v;
            if(line_iter + digit_iter < 9)
            {
                if(line_iter > digit_iter)
                {
                    p_v = abs(n-digit_iter);
                }
                else if (digit_iter >= line_iter)
                {
                    p_v = abs(n-line_iter);
                }
            }
            else if ((line_iter + digit_iter) >= 9)
            {
                if (line_iter < digit_iter)
                {
                    p_v++;
                }
            }
            printf("%d ", p_v);
        }
        printf ("\n");
    }
    return 0;
}

