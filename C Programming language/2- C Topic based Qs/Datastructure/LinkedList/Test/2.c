#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist* link;
} linkedlist;

int append_node ( linkedlist* Head, int data )
{
    linkedlist* newnode = (linkedlist*) malloc (sizeof(linkedlist));

    if (newnode != NULL)
    {
        newnode->data = data;
        newnode->link = NULL;
        linkedlist* current_pointer = Head;
        while (current_pointer->link != NULL)
        {
            current_pointer = current_pointer->link;
        }
        current_pointer->link = newnode;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{

    linkedlist *Head = (linkedlist*) malloc (sizeof(linkedlist));
    Head->data = 45;
    Head->link = NULL;

    append_node (Head , 98);
    append_node (Head , 3);

    linkedlist* current_Pointer = Head;

    //Free data
    while (current_Pointer != NULL)
    {
        linkedlist* next = current_Pointer->link;
        free(current_Pointer);
        current_Pointer = next;
    }

    return 0;
}