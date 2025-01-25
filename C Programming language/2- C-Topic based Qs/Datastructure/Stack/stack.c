#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
    int items[MAX];
    int top;
} Stack;

void initStack (Stack *s)
{
    s->top =-1;
}

int  isFull (Stack *s)
{
    return (s->top == MAX-1);
}

int isEmpty (Stack *s)
{
    return (s->top == -1);
}

void push(Stack *s, int value)
{
    if (isFull (s)
)
    {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop (Stack *s)
{
    if (!isEmpty(s))
    {
        int data = s->items[s->top];
        s->top--;
        return data;
    }
}

int peek (Stack *s)
{
    if (!isEmpty(s))
    {
        return (s->items[s->top]);
    }
}

