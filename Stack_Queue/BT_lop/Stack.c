#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int top;
    int a[MAX];
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX-1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        return;
    }
    s->a[++s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->a[s->top--];
}

void displayStack(Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ",s->a[i]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    init(&s);

    int num[6] = {1,-2,3,-4,5,-6};
    printf("MAX = %d\n\n",MAX);

    printf("PUSH\n\n");
    for (int i = 0; i < 6; i++)
    {
        printf("push %d:\n",num[i]);
        if (!isFull(&s))
        {
            push(&s,num[i]);
            displayStack(&s);
            printf("\n");
        }
        else
        {
            printf("Stack is full.\n\n");
        }
    }

    printf("POP\n\n");
    while (!isEmpty(&s))
    {
        printf("pop %d:\n",pop(&s));
        if (!isEmpty(&s))
        {
            displayStack(&s);
            printf("\n");
        }
        else
        {
            printf("Stack is empty.\n");
        }
    }

    return 0;
}
