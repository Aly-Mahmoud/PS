#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist * link;
} linkedlist;

linkedlist* append_node (linkedlist* last, int data)
{
    linkedlist* Current = (linkedlist*)malloc(sizeof(linkedlist));
    Current->data = data;
    Current->link = NULL;

    last->link = Current;

    return Current;
}

void add_node_at_position (linkedlist* Head, int data, int position)
{
    linkedlist* new_node = (linkedlist*)malloc (sizeof(linkedlist));
    linkedlist* next = Head;
    linkedlist* prev = Head;
    new_node->data = data;

    for (int i = 1; i<position-1; i++)
    {
        prev = prev->link;
    }
    next = prev->link;

    new_node->link = next;
    prev->link = new_node;

}

void print_node (linkedlist* Head)
{
    linkedlist* Current = (linkedlist*)malloc (sizeof(linkedlist));
    Current = Head;
    int count = 1;
    while (Current != NULL)
    {
        printf("\nNode no. %d value is = %d", count, Current->data);
        Current = Current->link;
        count++;
    }
}

int main ()
{
    linkedlist* Head = (linkedlist*) malloc (sizeof(linkedlist));
    linkedlist* Current;

    Head->data = 45;
    Head->link = NULL;

    Current = append_node (Head, 98);
    Current = append_node (Current, 3);

    add_node_at_position (Head, 67, 3);

    print_node (Head);

    return 0;
}