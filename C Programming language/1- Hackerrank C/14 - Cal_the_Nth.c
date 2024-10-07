#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
int arr[4]={0};
int i = 0;
int find_nth_term(int n, int a, int b, int c) 
{
  //Write your code here.
  switch (n)
  {
    case 1:
        return a;
    break;

    case 2:
        return b;
    break;

    case 3:
        return c;
    break;

    default:
        arr[0]= a;
        arr[1]= b;
        arr[2]= c;
        arr[3]= arr[0]+arr[1]+arr[2];
        
        while ( i < (n-4) )
        {
            i++;
            find_nth_term( n , arr[1] , arr[2] , arr [3] );
        }
        return arr[3];
    break;        
  }
}

int main() 
{
    int n, a, b, c;
  
    // scanf("%d %d %d %d", &n, &a, &b, &c);
    n=4;a=1;b=2;c=3;

    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    getchar();
    getchar();
    return 0;
}