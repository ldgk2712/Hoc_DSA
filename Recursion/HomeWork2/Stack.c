#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

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

void pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    s->top--;
    pop(s);
}

void displayStack(Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ",s->a[i]);
    }
    printf("\n");
}

void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

int main()
{
    Stack s;
    init(&s);
    time_t t;
    srand((unsigned)time(&t));
    int arr[20];
    initializeArray(arr,20,-10,10);
    for (int i = 0; i < 20; i++)
    {
        push(&s, arr[i]);
    }
    displayStack(&s);
    pop(&s);
    

    return 0;
}
