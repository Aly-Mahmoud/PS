#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist* link;
} linkedlist;

int append_node_On ( linkedlist* Head, int data )
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

linkedlist* append_node_O1 ( linkedlist* current, int data )
{
    linkedlist* newnode = (linkedlist*) malloc (sizeof(linkedlist));

    newnode->data= data;
    newnode->link= NULL;

    current->link = newnode;

    return newnode;

}

void print_all_nodes (linkedlist* Head)
{
    linkedlist* current_pointer = Head;
    int count = 1;

    while (current_pointer->link != NULL) 
    {
        printf("\nthe data of node %d is %d ", count , current_pointer->data);
        printf("\nthe address of next-node is %p ", current_pointer->link);
        count++;
        current_pointer = current_pointer->link;
    }
        printf("\nthe data of node %d is %d ", count , current_pointer->data);
        printf("\nthe address of next-node is %p ", current_pointer->link);

}

void count_all_nodes (linkedlist* Head)
{
    linkedlist* current_pointer = Head;
    int count = 0;

    while (current_pointer->link != NULL) 
    {
        count++;
        current_pointer = current_pointer->link;
    }

    printf("\nThe number of nodes are %d", count+1);
}


int main ()
{

    linkedlist *Head = (linkedlist*) malloc (sizeof(linkedlist));
    Head->data = 45;
    Head->link = NULL;

    // append_node_On (Head , 98);
    // append_node_On (Head , 3);

    linkedlist* Current;

    Current = append_node_O1(Head,98);
    Current = append_node_O1(Current,3);

    print_all_nodes(Head);

    count_all_nodes(Head);

    Current = Head;

    //Free data
    while (Current != NULL)
    {
        linkedlist* next = Current->link;
        free(Current);
        Current = next;
    }

    return 0;
}