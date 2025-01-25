#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *link;
};

struct node* reverse (struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;

    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main ()
{
/*-=creating the head ptr and the first node=-*/
    struct node *head = NULL;
    head = (struct node *) malloc (sizeof(struct node));
    head->data =45;
    head->link = NULL;
/*-----------------------------------------*/

/*-=creating the current ptr and the 2nd node=-*/
    struct node *current = NULL;
    current = (struct node *) malloc (sizeof(struct node));
    current->data= 98;
    current->link= NULL;
/*-----------------------------------------*/

/*Linking the first node with the 2nd node*/
    head->link = current;
/*-----------------------------------------*/

/*-=creating the 3rd node=-*/
    current = (struct node *) malloc (sizeof(struct node));
    current->data = 3;
    current->link = NULL;
/*-------------------------*/

/*Linking the 2nd node with the 3rd node*/
    head->link->link = current;
/*--------------------------------------*/

return 0;
}
