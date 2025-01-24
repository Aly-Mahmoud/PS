#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *link;
};

count_of_nodes(struct node *head)
    {
		int count = 0;
		if (head == NULL)
		{
			printf("Linked List is empty");
		}
		else 
		{
			struct node *ptr = NULL;
			ptr=head;
            while (ptr != NULL)
            {
                count++;
                ptr= ptr->link;
            }
            printf("%d", count);
		}

    }

int main ()
{

}