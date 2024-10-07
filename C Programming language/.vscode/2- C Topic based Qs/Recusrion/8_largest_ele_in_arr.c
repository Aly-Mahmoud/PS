#include <stdio.h>
#include <stdlib.h>

int largest_ele_in_arr( int* arr , int size , int iter)
{
    static int max = 0;
    if ( size > iter )
    {
        if (arr[iter] > max)
            max = arr[iter];
        largest_ele_in_arr(arr, size , ++iter);
    }
    else 
        return max;
}

int main ()
{
    int size;
    int iter = 0;
    scanf( "%d\n" , &size );
    int* arr = (int*)malloc (sizeof(int)*size);

    for (int iter = 0; iter < size ; iter++)
    {
        scanf( "%d" , &arr[iter] );
    }

    printf( "%d" ,largest_ele_in_arr( arr , size , iter));


    getchar();
    getchar();
    return 0;
}