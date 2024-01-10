#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
    int top;
    char items[MAX];
    /* data */
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isFulL(Stack *s)
{
    return s->top == MAX-1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char item)
{
    if (isFulL(s))
    {
        return;
    }
    s->items[++s->top] = item;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->items[s->top--];
}

void reverseStack(Stack *s)
{
    printf("ReverseString - Stack: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c",s->items[i]);
    }
    printf("\n");
}

void reverseArr(char *str)
{
    printf("ReverseString - Array: ");
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main()
{
    char str[MAX];
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
    Stack s;
    init(&s);

    for (int i = 0; i < strlen(str); i++)
    {
        push(&s, str[i]);
    }

    reverseArr(str);
    reverseStack(&s);

    return 0;
}
