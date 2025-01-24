#include <stdio.h>
#include <string.h>

int main()
{
    char str [50];
    printf("Please enter you text:");
    fgets(str, sizeof str, stdin);

    int counter = 0;
    char* chr;

    chr = (char*)str;

    while (*chr != '\0' && *chr != '\n')
    {
        chr++;
        counter++;
    }

    printf("The length of your text is: %d ",counter);
}