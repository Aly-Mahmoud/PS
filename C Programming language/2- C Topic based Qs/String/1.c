#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    printf("Please enter your text:");
    fgets(str,sizeof str, stdin);
    printf("\n the text you entered is: %s\n " , str);
    getchar();
    return 0;
}