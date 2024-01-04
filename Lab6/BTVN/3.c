#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Stack_type{
    int a[MAX_SIZE];
    int top;
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
    return s->top == MAX_SIZE-1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        return;
    }
    s->a[++(s->top)] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->a[s->top--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }    
}

void preSolve(Stack *operandStack, Stack *operatorStack)
{
    int operand2 = pop(operandStack);
    int operand1 = pop(operandStack);
    char operator = pop(operatorStack);

    switch (operator)
    {
    case '+':
        push(operandStack, operand1 + operand2);
        break;
    case '-':
        push(operandStack, operand1 - operand2);
        break;
    case '*':
        push(operandStack, operand1 * operand2);
        break;
    case '/':
        push(operandStack, operand1 / operand2);
        break;
    }
}

void solve(char *string)
{
    Stack operandStack, operatorStack;
    init(&operandStack);
    init(&operatorStack);
    int i = 0;

    while (string[i] != '\0')
    {
        char token = string[i];
        
        if (isdigit(token))
        {
            push(&operandStack, token - '0');
        }
        else if (isOperator(token))
        {
            while (!isEmpty(&operandStack) && getPrecedence(token) <= getPrecedence(operatorStack.a[operatorStack.top]))
            {
                preSolve(&operandStack, &operatorStack);
            }
            push(&operatorStack, token);
        }
        i++;
    }

    while (!isEmpty(&operatorStack)) {
        preSolve(&operandStack, &operatorStack);
    }

    printf("Result: %d\n",pop(&operandStack));
}

int main() {
    char expression[MAX_SIZE];

    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    solve(expression);
    
    return 0;
}