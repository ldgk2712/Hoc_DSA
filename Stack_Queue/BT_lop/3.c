#include <stdio.h>
#define MAX 7;

typedef struct 
{
    int a[MAX];
    int head, tail;
} CircularQueue;

void init(CircularQueue *cq)
{
    cq->head = -1;
    cq->tail = -1;
}

int isEmpty(CircularQueue *cq)
{
    return cq->head == -1;
}

int isFull(CircularQueue *cq)
{
    return (cq->tail + 1) % MAX == cq->head;
}

void enqueue(CircularQueue *cq, int value)
{
    if (isFull(cq))
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(cq))
    {
        cq->head = 0;
    }

    cq->tail = (cq->tail + 1) % MAX;
    cq->a[cq->tail] = value;
}

int dequeue(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int dequeuedValue = cq->a[cq->head];

    if (cq->head == cq->tail)
    {
        cq->head = -1;
        cq->tail = -1;
    }
    else
    {
        cq->head = (cq->head + 1) % MAX;
    }

    return dequeuedValue;
}

void displayCircularQueue(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = cq->head;
    while (i != cq->tail) {
        printf("%d ", cq->a[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", cq->a[i]);
}