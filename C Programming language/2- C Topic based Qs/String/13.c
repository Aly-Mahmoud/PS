#include <stdio.h>

int main ()
{
    char str [50];
    int str_index = 0;
    int sub_string_length =0;

    printf("Input the string : ");
    scanf("%s",&str);

    printf("\nInput the position to start extraction :");
    scanf("%d",&str_index);
    printf("\nInput the length of substring :");
    scanf("%d",&sub_string_length);

    printf("The substring retrieve from the string is :");

    for (int i = str_index-1 ; i< (str_index + sub_string_length -1) ; i++)
    {
        printf("%c", str[i]);
    }

    return 0;
}