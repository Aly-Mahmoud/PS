#include <stdio.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist * link;
} linkedlist;

void front_append (linkedlist* Head, int data)
{
    linkedlist * Current = (linkedlist*) malloc (sizeof(linkedlist));
    Current->data = data;
    Current->link = Head;

    Head = Current;
}

int main ()
{

    linkedlist * Head = (linkedlist*) malloc (sizeof(linkedlist));

    Head->data = 45;
    Head->link = NULL;

    front_append (Head, 100);


    return 0;
}