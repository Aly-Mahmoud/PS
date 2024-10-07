#include <stdio.h>
#include <stdlib.h>

int iter = 0;

void is_even_odd ( int min_range , int max_range , int* even_arr , int* odd_arr)
{
    if(min_range > max_range)
    {
        return;
    }
    else if(min_range%2 == 0)
    {
        even_arr[iter] = min_range;
        iter++;
    }
    else
    {
        odd_arr[iter] = min_range;
    }
    is_even_odd( min_range+1 , max_range , even_arr , odd_arr);
}

int main ()
{
    int min_range;
    int max_range;
    printf("=====Enter range====\n");
    printf("From: ");
    scanf("%d", &min_range);
    printf("To: ");
    scanf("%d", &max_range);

    int range = max_range-min_range + 1;
    int even_range;
    int odd_range;

    if ( range%2 == 0 )
    {
        even_range = range/2;
        odd_range  = range/2;
    }
    else 
    {
        even_range = range/2;
        odd_range = even_range+1;
    }

    int* even_arr = (int*)malloc(sizeof(int)*even_range);
    int* odd_arr  = (int*)malloc(sizeof(int)*odd_range );

    is_even_odd ( min_range , max_range , even_arr , odd_arr );

    printf("All even numbers from %d to %d are : " , min_range , max_range );

    for(int i = 0 ; i<even_range ; i++)
    {
        printf("%d " , even_arr[i]);   
    }

    printf("\nAll odd  numbers from %d to %d are : " , min_range , max_range );

    for(int i = 0 ; i<odd_range ; i++)
    {
        printf("%d " , odd_arr[i]);   
    }

    getchar();
    getchar();

    return 0;
}