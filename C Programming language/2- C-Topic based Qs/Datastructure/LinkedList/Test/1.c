#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedlist *node ;
}   linkedList;

// int main ()
// {
//     linkedList L1;
//     linkedList* Head = &L1;
//     L1.data = 45;
//     L1.node = NULL;

//     printf("\nthe address of head is: %p", Head);
//     printf("\nthe data inside the first node is : %d", L1.data);
//     printf("\nthe address of the next node is : %p", L1.node);

//     return 0;
// }


int main ()
{

    linkedList* Head ;

    Head = (linkedList*)malloc(sizeof(linkedList)*1);

    Head->data = 45;
    Head->node = NULL;

    printf("\nthe address of head is: %p", Head);
    printf("\nthe data inside the first node is : %d", Head->data);
    printf("\nthe address of the next node is : %p", Head->node);

    return 0;    

}