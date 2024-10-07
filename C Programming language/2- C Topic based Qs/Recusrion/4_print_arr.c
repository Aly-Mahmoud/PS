#include <stdio.h>
#include <stdlib.h>

void print_arr(int* arr,int size, int iter)
{
    if (size == iter)
    {
        return;
    }
    printf("%d " , arr[iter]);
    print_arr(arr,size,++iter);

}

int main ()
{
    int size;
    int i;
    scanf("%d\n", &size);

    int* arr = (int*) malloc (sizeof(int)*size);
    for ( i = 0 ; i<size ; i++)
    {
        scanf ("%d", &arr[i]);
    }


    print_arr(arr,size,0);

    free(arr);
    return 0;
}