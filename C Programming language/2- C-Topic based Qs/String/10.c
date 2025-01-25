#include <stdio.h>

int main ()
{

    int hash_table [123]={0};

    char str [50];
    int hfc =0;
    int freq =0;

    printf("Write text : ");
    fgets(str,sizeof str, stdin);

    int counter=0;

    while (str[counter] != '\n' && str[counter] != '\0')
    {
        if ((str[counter] >= 'A' && str[counter] <= 'Z') || (str[counter] >= 'a' && str[counter] <= 'z'))
        {
            hash_table[(int)str[counter]]++;
        }
        counter++;
    }

    for (int i = 65; i < 123 ; i++)
    {
        if (hash_table[i] > freq)
        {
            freq = hash_table[i];
            hfc = i;
        }
    }

    printf("The Highest frequency of character '%c'\n", hfc);
    printf("appears number of times : %d ", freq);

    return 0;
}