#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int e_count;
    printf ("\nInput the number of elements to store in the array : ");
    scanf ("%d",&e_count);

    int *array;
    array = (int*)malloc (e_count*sizeof(int));

    if (array == NULL)
    {
        printf("\nMemory allocation failed!");
        return 1;
    }

    for (int i = 0 ; i < e_count ; i++)
    {
        printf("\nplease enter element number %d value : ", i+1 );
        scanf("%d", &array[i]);
    }

    for (int i = 0 ; i < e_count ; i++)
    {
        printf("\nelement number %d value : %d ", i+1 , array[i]);
    }

    return 0;
}