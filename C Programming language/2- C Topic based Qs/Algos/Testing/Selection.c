void swap (int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void xor_swap (int* a, int* b)
{
    if (*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

void ar_swap (int* a, int* b)
{
    if (*a != *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

void SelectionSort (int* data, int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i<size-1; i++)
    {
        for (j=i+1; j<size; j++)
        {
            if (data[i] > data[j])
                swap (&data[i], &data[j]);
        }
    }
}