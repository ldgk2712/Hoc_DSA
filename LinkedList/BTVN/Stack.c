#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int data;
    struct NodeType* next;
} Node;

typedef struct LinkedListType_Stack
{
    Node *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

Node *makeNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(Stack *s, int data)
{
    Node *node = makeNode(data);
    node->next = s->top;
    s->top = node;
}

int pop(Stack *s)
{
    if (s->top == NULL)
    {
        return -1;
    }
    int s_pop = s->top->data;
    Node *node = s->top->next;
    s->top = node;
    return s_pop;
}

void printStack(Stack *s)
{
    Node *node = s->top;
    while (node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Stack stack;
    initStack(&stack);

    int a[] = {32, 20, 11, -25, -42};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        push(&stack, a[i]);
    }

    printf("Ngan xep sau khi them phan tu:\n");
    printStack(&stack);

    int val = pop(&stack);
    printf("Phan tu o dinh ngan xep hien tai: %d\n", val);

    printf("Ngan xep sau khi loai bo phan tu:\n");
    printStack(&stack);

    return 0;
}