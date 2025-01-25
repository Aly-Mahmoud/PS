
/*
int main()
{
    char str1 [50];
    char str2 [50];

    int counter1=0;
    int counter2 =0;

    int flag = 0;

    printf("Enter 1st string: ");
    fgets(str1,sizeof str1, stdin);

    printf("\nEnter 2nd string: ");
    fgets(str2,sizeof str2, stdin);

    while (str1[counter1] != '\0' && str1[counter1] != '\n')
    {
        counter1++;
    }

    while ( str2[counter2] != '\0' && str2[counter2] != '\n' )
    {
        counter2++;
    }

    if (counter1 != counter2)
    {
        flag = 1;
    }
    else
    {
        counter1 =0;
        counter2 =0;

        while (str1[counter1] != '\0' && str1[counter1] != '\n')
        {
            if (str1[counter1] != str2[counter2])
            {
                flag =1;
                break;
            }
            else
            {
                counter1++;
                counter2++;
            }
        }
    }

    if (flag == 1)
    {
        printf("\nStrings are not equal");
    }
    else
    {
        printf("\nStrings are equal");
    }

    return 0;
}
*/

#include <stdio.h>
int flag = 0;

int test (char* s1, char* s2)
{
    while ( *s1 != '\n' || *s2 != '\n')
    {
        if ( *s1 == *s2 )
        {
            s1++;
            s2++;
        } 
        else
        {
            flag = 1;
            break;
        }
    }
}

int main ()
{
    char str1 [50];
    char str2 [50];

    printf("Enter 1st string: ");
    fgets(str1,sizeof str1, stdin);

    printf("\nEnter 2nd string: ");
    fgets(str2,sizeof str2, stdin);

    test (str1,str2);

    if (!flag)
    {
        printf("strings are identical");
    }
    else
    {
        printf("strings are not identical");
    }

    return 0;    
}