#include <stdio.h>

#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int tail, head;
    int items[MAX_SIZE];
} Queue;

void init(Queue *q)
{
    q->tail = -1;
    q->head = 0;
}

int isFull(Queue *q)
{
    return (q->tail - q->head + 1) == MAX_SIZE;
}

int isEmpty(Queue *q)
{
    return q->head > q->tail;
}

void push(Queue *q, int value)
{
    if (isFull(q))
    {
        return;
    }
    q->items[++q->tail] = value;
}

int get(Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->items[q->tail--];
}

void solve(int arr[], int k, int n)
{
    int arrNew[n+1] = {0};
    for (int i = 1; i < n+1; i++)
    {
        arrNew[i] = arrNew[i-1] + arr[i-1];
    }
    int sum = arrNew[n];
    
}