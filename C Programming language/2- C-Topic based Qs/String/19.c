#include <stdio.h>
#include <string.h>

int main()
{
    char str_1 [50];
    char str_2 [50];
    int j =0;

    printf("\nInput the first string : ");
    fgets (str_1, sizeof(str_1),stdin);
    printf("\nInput the second string : ");
    fgets (str_2, sizeof(str_2),stdin);

    int str1_size = strlen(str_1) - 1;
    int str2_size = strlen(str_2) - 1;
    int total_str_size = str1_size+str2_size;

    for (int i = str1_size ; i < total_str_size ; i++,j++)
    {
        str_1[i] = str_2[j];
    }

    str_1[total_str_size] = '\0';

    printf("After concatenation the string is : %s", str_1);

    getchar();
    getchar();

    return 0;
}