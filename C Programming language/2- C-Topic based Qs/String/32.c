#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str [50];
    int ht [123] = {0};

    printf("\nInput a string: ");
    fgets(str,sizeof(str),stdin);

    int length = strlen(str);
    int index =-1;

    for (int i = 0; i < length ; i++)
    {
        if ( isalpha(str[i]) )
        {
            ht[str[i]]++;
        }
    }

    for (int i = 65; i<= 122  ; i++)
    {
        if (ht[i] > 1)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("there is no reprtitive character in %s", str);
    }
    else 
    {
        printf("The first repetitive character in %s is %c", str , index );
    }

    return 0;
}