#include <stdio.h>
#include <stdlib.h>
/*
Constrains deduced from the answer:
0 < size of array < 102
0 < array element <= 100
*/

int find_min_occurance( int *arr , int size)
{
    int min_occurance= 101;
    int min_occurance_number = 0;

    if (size <= 0)
    {
        return 0;
    }

    if (size == 1)
    {
        return *arr;
    }

    int HashTable[102];

    for (int init=0;init<102;init++)
    {
        HashTable[init] = 0;
    } 

    for (int i=0;i<size;i++)
    {
        HashTable[arr[i]]++; 
    }

    for (int j=0;j<102;j++)
    {
        if (HashTable[j] < min_occurance && HashTable[j] > 0)
        {
            min_occurance = HashTable[j];
            min_occurance_number = j;
        }
    }
    return min_occurance_number;
}

int main ()
{
    int size;
    int element;
    int min_occurance_number;

    do
    {
        printf("\nConstrains:\n0 < size of array < 102\nPlease enter size of array : ");
        scanf("%d", &size);
    } while (size <= 0 || size >= 102);

    int* arr = malloc(sizeof(int)*size);

    for (int i = 0; i<size ; i++)
    {
        do 
        {
            printf("\nConstrains:\n0 < array element <= 100\nPlease enter input number %d : ", i+1);
            scanf("%d", &element);
        }
        while (element < 0 || element > 100);

        arr[i] = element;
    }

    min_occurance_number = find_min_occurance( arr , size);

    printf("\nThe number min_occurance is : %d", min_occurance_number);

    getchar(); 
    free (arr);

    return 0;
}