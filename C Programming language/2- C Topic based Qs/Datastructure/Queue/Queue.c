#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int* que;
    int size;
    int rear;
}   Queue;

void InitQueue (Queue* Q, int size)
{
    Q->size = size;
    Q->rear = 0;
    Q->que = (int*) malloc (sizeof(int)*size); 
}

int IsFull (Queue* Q)
{
    return ( Q->size == (Q->rear) );
}

int IsEmpty (Queue* Q)
{
    return (Q->rear == 0);
}

int enqeue (Queue* Q, int data)
{
    if (!isFull(Q))
    {
        Q->que[Q->rear] = data;
        Q->rear++;
        return 1;
    } 
    else 
        return 0;
}

int deqeue (Queue* Q, int *data)
{
    if (!IsEmpty(Q))
    {
        data = Q->que[0];

        for (int i = 0; i<Q->rear; i++)
        {
            Q->que[i]=Q->que[i+1];
        }

        Q->rear--;

        return 1;
    }
    else
    {
        return -1;
    }
}

int peek (Queue* Q, int *data)
{
    if (!isEmpty(Q))
    {
        data = Q->que[0];
        return 1;
    }
    else
    {
        return 0;
    }
}


