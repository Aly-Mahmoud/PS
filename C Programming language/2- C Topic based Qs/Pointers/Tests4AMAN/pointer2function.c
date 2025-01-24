#include <stdio.h>

int saymename ()
{
    printf("Your are Heizenburg");
    return 1;
}

void replay ()
{
    printf("\nYou are god damn right");
}


int main ()
{
    int(*p1func)() = saymename;
    void(*p2func)() = replay;

    if(p1func())
    {
        p2func();
    }

    return 0;
}