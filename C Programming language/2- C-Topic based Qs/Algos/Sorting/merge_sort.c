#include <stdlib.h>

void merge (int *a, int *l, int leftcount, int *r, int rightcount)
{
    int i = 0; // l
    int j = 0; // r
    int k = 0; // a

    while (i<leftcount && j<rightcount)
    {
        if (l[i] < r[j])
        {
            a[k++] = l[i++];
        }
        else
        {
            a[k++] = r[j++];
        }
    }
    while (i<leftcount)
    {
        a[k++] = l[i++];
    }
    while (j<rightcount)
    {
        a[k++] = r[j++];
    }
}

void merge_sort ( int *arr, int size)
{
    int i;
    int mid;
    int *l;
    int *r;


    if (size<2)
    {
        return;
    }

    mid = size/2;

    l = (int*)malloc (mid*sizeof (int));
    r = (int*)malloc ((size-mid)*sizeof(int));

    for (i = 0; i<mid ; i++)
    {
        l[i] = arr[i];
    }
    for ( i = mid ; i<size ; i++)
    {
        r[i-mid] = arr[i];
    }

    merge_sort(l,mid);
    merge_sort(r,size-mid);
    merge(arr,l,mid,r,size-mid);

    free (l);
    free (r);

}