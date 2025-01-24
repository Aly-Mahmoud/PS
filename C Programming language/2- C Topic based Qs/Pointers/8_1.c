#include <stdio.h>
#include <string.h>

void swapchar (char* ch_1, char* ch_2)
{
    char temp;
    temp = *ch_1;
    *ch_1 = *ch_2;
    *ch_2 = temp;
}

void charPermutation (char *str, int stno, int endno)
{
    if (stno == endno)
    {
        printf("\n%s", str);
    }
    else 
    {
        for (int i = stno ; i <= endno ; i++)
        {
            swapchar ( (str+stno) , (str+i) );
            charPermutation ( str , stno+1 , endno );
            swapchar ( (str+stno) , (str+i) );
        }

    }
}

int main ()
{
    char str [] = {"abcd"};
    int n = strlen(str);

    charPermutation (str, 0 , n-1);

    return 0;
}