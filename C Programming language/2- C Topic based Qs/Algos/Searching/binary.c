int binary_search (int* arr, int size, int key)
{
    int i;
    int low=0;
    int high=size-1;
    int mid = (low+high)/2;

    while (high >= low)
    {
        mid = (low+high)/2;
        
        if (arr[mid] > key)
            high= mid-1;
        else if (arr[mid] < key)
            low = mid+1;
        else    
            return mid;
    }
    return -1;
}