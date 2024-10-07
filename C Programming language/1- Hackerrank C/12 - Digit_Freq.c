#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char* s;
    scanf("%s", s);
    // char*s = "as12as23as56as90";
    int arr[10]={0};
    char* num = s;

    for (int i =0; i< strlen(s); i++)
    {
        if ( (*num >= 48) && (*num <= 57) )
        {
            arr[*num - 48]++; // 48 = '0'
        }
        num++;
    }

    for (int j=0; j<10 ;j++)
    {
        printf("%d ", arr[j]);
    }

    getchar();
    getchar();
    return 0;
}
