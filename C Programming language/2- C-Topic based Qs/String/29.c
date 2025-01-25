#include <stdio.h>
#include <ctype.h>

int main ()
{
    FILE * pfile;
    char a;

    pfile = fopen("29.txt","r");

    if (pfile)
    {
        do 
        {
            a = fgetc(pfile);
            if (isgraph(a))
            {
                printf("%c",a);
            }
        }
        while (a != EOF);
        
        fclose(pfile);

    }
    return 0;
}