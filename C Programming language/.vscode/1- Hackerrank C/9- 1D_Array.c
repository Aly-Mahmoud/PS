#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int size;
    int sum = 0;

    scanf ("%d\n", &size);
    int* arr = (int*) malloc(size*sizeof(int));

    for(int iter = 0 ; iter < size ; iter++)
    {
        scanf("%d", &arr[iter]);
    }
    
    for (int j=0 ; j<size ; j++ )
    {
        sum += arr[j];
    }

    printf("%d\n",sum);

    free(arr);

    getchar();
    getchar();
    
    return 0;
}