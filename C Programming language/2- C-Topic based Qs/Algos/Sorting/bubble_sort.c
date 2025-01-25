void XORswap (int *a, int *b)
{
    if (*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

void bubble_sort (int *arr, int size)
{
    int i = 0;
    int j = 0;
    int swapped;

    for (i=0; i<size-1; i++)
    {
        swapped = 0;
        for (j=0; j<size-1-i ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                XORswap (&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}