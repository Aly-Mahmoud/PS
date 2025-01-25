#include <stdio.h>
#include <stdlib.h>
struct node 
{
int data;
struct node *link;
};

int main ()
{
/*-=creating the head ptr and the first node=-*/
    struct node *head = NULL;                            //creating a head ptr of the type node
    head = (struct node *) malloc(sizeof(struct node));  // allocating memory for the first element 
    head->data = 45;                                     // accessing the node's data through the head pointer & initializing it
    head->link = NULL;                                   // accessing the node's link through the head pointer & initilizing it
/*-----------------------------------------*/

printf ("%d", head-> data);
return 0;
}