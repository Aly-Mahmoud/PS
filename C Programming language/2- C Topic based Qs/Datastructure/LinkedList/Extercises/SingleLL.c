#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* link;
};

int count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count ++;
        ptr = ptr->link;
    }
    printf("%d" , count);
    return count;
}

void Print_data (struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr-> data);
        ptr = ptr->link;
    }
}
int add_at_end (struct node *head , int data )
{
    struct node *temp = head;
    struct node new_node;
    new_node.data = data;
    new_node.link = NULL;

    if (head = NULL)
    {
        return 0;
    }
    else 
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        
    }
}

int main ()
{
    struct node *head = (struct node *)malloc (sizeof(struct node));
    head->data = 45;
    head ->link = NULL;

    struct node *current = (struct node *) malloc (sizeof(struct node));
    current->data = 98;
    current ->link = NULL;

    head->link = current;

    current = (struct node *) malloc (sizeof (struct node));
    current->data = 3;
    current -> link = NULL;

    head->link->link = current;

    printf("%d , %d , %d" , head-> data, head->link->data, current->data );
    return 0 ;
}