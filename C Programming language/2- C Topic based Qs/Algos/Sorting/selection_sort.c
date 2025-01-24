#include <stdio.h>

void XORswap (int *a, int *b)
{
    if (*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

void ar_swap (int *a, int *b)
{
    if (*a != *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

void temp_swap (int *a, int *b)
{
    if (*a != *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void selection_sort (int *arr , int size)
{
    int i = 0;
    int j = 0;

    for (i=0 ; i<size-1 ; i++)
    {
        for (j=i+1; j<size ; j++)
        {
            if (arr[i] > arr[j])
            {
                XORswap (&arr[i], &arr[j]);
            }
        }
    }
}

void selection_sort_optomized (int *arr , int size)
{
    int i = 0;
    int j = 0;
    int min_index;

    for (i=0 ; i<size-1 ; i++)
    {
        min_index = i;
        for (j=i+1; j<size ; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            XORswap (&arr[i], &arr[j]);
        }
    }
}


