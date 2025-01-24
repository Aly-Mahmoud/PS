#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * link;
} node;

struct node* reverse (struct node* Head)
{
    struct node* prev =NULL;
    struct node* next = NULL;

    while (Head!= NULL)
    {
        next = Head->link;
        Head->link = prev;
        prev = Head;
        Head = next;
    }
    Head = prev;
    return Head;
}

