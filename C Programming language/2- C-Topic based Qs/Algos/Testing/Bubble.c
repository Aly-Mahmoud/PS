void BubbleSort (int* data, int size)
{
    int i = 0;
    int j = 0;
    int swapped = 0;

    for (i=0; i<size-1; i++)
    {
        swapped =0;
        for (j=0; j<size-i-1; j++)
        {
            if (data[j]>data[j+1])
            {
                swap(&data[i], &data[j+1]);
                swapped = 1;
            }
        }
        if (swapped =0)
            break;
    }
}