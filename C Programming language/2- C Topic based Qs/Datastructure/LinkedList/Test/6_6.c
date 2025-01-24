#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
} node;

node* append_node (node*last, int data)
{
    node*current = (node*) malloc (sizeof(node));
    current->data = data;
    current->link = NULL;

    last->link = current;

    return current;
}

int count_node (node* Head)
{
    node* current = Head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current=current->link;
    }
    return count;
}

void shift_linkedlist (node** Head, int shift_value)
{
    node* current = *Head;

    int count = 1;
    while (current->link != NULL)
    {
        count++;
        current=current->link;
    }

    current->link = *Head;

    current = *Head;

    for (int i = 1; i< (count-shift_value); i++ )
    {
        current = current->link;
    }
    
    *Head = current; 
    current->link = NULL;


}