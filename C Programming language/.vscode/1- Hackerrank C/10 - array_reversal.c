#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int num, *arr, i;
    // scanf("%d", &num);
    // arr = (int*) malloc(num * sizeof(int));
    // for(i = 0; i < num; i++) 
    // {
    //     scanf("%d", arr + i);
    // }

    int num = 6;
    int* arr = (int*) malloc(num * sizeof(int));
    arr[0]=16;
    arr[1]=13;
    arr[2]=7;
    arr[3]=2;
    arr[4]=1;
    arr[5]=12; 

    /* Write the logic to reverse the array. */
    int j= num-1;
    int isodd = num%2;
    int terminator;
    if (isodd)
    {
        terminator = num/2;
    } 
    else
    {
        terminator = num/2-1;
    }
    for(int i=0 ; i<=terminator ; i++)
    {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j--;
    }
    

    for(int i = 0; i < num; i++)
        printf("%d ", *(arr + i));


    getchar();
    getchar();    
    return 0;
}