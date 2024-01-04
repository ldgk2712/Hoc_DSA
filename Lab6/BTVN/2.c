#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct
{
    int top;
    char items[MAX_SIZE];
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
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char item)
{
    if (isFull(s))
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

int check(char left, char right)
{
    if (left == '(' && right == ')' ||
        left == '[' && right == ']' ||
        left == '{' && right == '}' )
    {
        return 1;
    }
    return 0;
}

void solve(char *string)
{
    Stack s;
    init(&s);
    int countErr = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            push(&s, string[i]);
        }
        else if (string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            if (!isEmpty(&s))
            {
                char popped = pop(&s);
                if (!check(popped,string[i]))
                {
                    countErr++;
                    printf("Error at %d\n",i);
                    if (popped == '(')
                    {
                        string[i] = ')';
                    }
                    else if (popped == '[')
                    {
                        string[i] = ']';
                    }
                    else if (popped == '{')
                    {
                        string[i] = '}';
                    }
                }
            }
        }
    }
    if (countErr)
    {
        printf("%s\n",string);
    }
    else
    {
        printf("No Error.\n");
    }
}

int main()
{
    char string[MAX_SIZE];
    fgets(string, sizeof(string), stdin);
    if (string[strlen(string)-1] == '\n')
    {
        string[strlen(string)-1] = '\0';
    }
    solve(string);
    return 0;
}