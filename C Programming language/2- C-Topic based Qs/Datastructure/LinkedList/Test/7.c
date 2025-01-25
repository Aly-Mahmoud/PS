#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist * link;
} linkedlist;

linkedlist* append_node (linkedlist* last , int data)
{
    linkedlist* Current = (linkedlist*) malloc (sizeof(linkedlist));
    Current->data = data;
    Current->link = NULL;
    last->link = Current;

    return Current;
}

int delete_node (linkedlist** Head, int position)
{
    linkedlist*prev    ;
    linkedlist*current ;
    linkedlist*next    ;

    if (*Head != NULL)
    {
        if (position == 1)
        {
            current = *Head;
            *Head = current->link;
            free (current);
            return 1;
        }
        else 
        {
            prev = *Head;
            int count = position-1 ;
            /*Transverse the linked list to position to prev*/
            while (count != 0)
            {
                if ( prev == NULL)
                {
                    printf("\nError : Position does not match size");
                    return 0;
                }
                else 
                {
                    prev = prev->link;
                    count --;
                }
            }
            /*intializing current from prev*/
            if (prev->link != NULL)
            {
                current = prev->link;
            }

            /*last node*/
            if (current->link == NULL)
            {
                prev->link = NULL;
                free(current);
                return 1;
            }
            /*node in the middle*/
            else
            {
                prev->link = current->link;
                free(current);
                return 1;
            }
        }
    
    }
    else 
    {
        printf("\nError : Zero size linked list ");
        return 0;
    }
}

void print_nodes (linkedlist* Head)
{
    if (Head == NULL)
    {
        printf("\n Printfunction Error : Zero size LinkedList");
        return;
    }
    else
    {
        linkedlist* Current = Head;
        int count = 1;
        
        while ( Current != NULL)
        {
            printf("\nNode no. %d value is = %d", count, Current->data);
            Current = Current->link;
            count++;
        }
        
    }

}

int main ()
{
    linkedlist* Head = (linkedlist*) malloc (sizeof(linkedlist));
    Head->data = 1;
    Head->link = NULL;

    linkedlist* Current;
    Current = append_node(Head, 2);
    Current = append_node(Current, 3);
    Current = append_node(Current, 4);

    print_nodes (Head);
    printf("\n-------------------------------------------");
    delete_node (&Head, 2);
    print_nodes (Head);
    printf("\n-------------------------------------------");
    delete_node (&Head, 1);
    print_nodes (Head);
    printf("\n-------------------------------------------");
    delete_node (&Head, 2);
    print_nodes (Head);
    printf("\n-------------------------------------------");
    delete_node (&Head, 1);
    print_nodes (Head);
    printf("\n-------------------------------------------");

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