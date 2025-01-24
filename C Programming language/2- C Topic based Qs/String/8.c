#include <stdio.h>
#include <string.h>

#define string_size 50

// int main ()
// {
    // char str1 [string_size];
    // char str2 [string_size];

    // fgets(str1,sizeof str1,stdin);

//     strcpy(str2,str1);

//     int counter1 = 0;
//     int counter2 = 0;

    // printf("%s",str1);
    // printf("%s",str2);

    // return 0;
// }

int main ()
{
    char str1 [string_size];
    char str2 [string_size];

    fgets(str1,sizeof str1,stdin);

    int counter = 0;

    while (str1[counter] != '\0')
    {
        str2[counter] = str1[counter];
        counter++;
    }
        str2[counter] = str1[counter];

    printf("%s",str1);
    printf("%s",str2);

    return 0;

}