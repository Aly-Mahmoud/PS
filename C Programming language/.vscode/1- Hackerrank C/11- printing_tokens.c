#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    // s = "This is Aly";
    //Write your logic to print the tokens of the sentence here.     
    char* letter=s;

    while (*letter != '\0')
    {
        if(*letter == ' ')
        {
            printf("\n");
        }
        else 
        {
            printf("%c", *letter);
        }
        letter++;
    }
    free(s);
    return 0;
}