#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue
{
    int tail, head;
    int a[MAX];
} Queue;

void init(Queue *q)
{
    q->tail = -1;
    q->head = 0;
}

int isFull(Queue *q)
{
    return q->tail == MAX-1;
}

int isEmpty(Queue *q)
{
    return q->head > q->tail;
}

void put(Queue *q, int value)
{
    if (isFull(q))
    {
        return;
    }
    q->a[++q->tail] = value;
}

int get(Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->a[q->head++];
}

void displayQueue(Queue *q)
{
    for (int i = q->head; i <= q->tail; i++)
    {
        printf("%d ",q->a[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    init(&q);
    int num[6] = {1,-2,3,-4,5,-6};

    printf("MAX = %d\n\n", MAX);
    printf("PUSH\n");

    for (int i = 0; i < 6; i++)
    {
        printf("put %d:\n",num[i]);
        if (!isFull(&q))
        {
            put(&q,num[i]);
            displayQueue(&q);
        }
        else
        {
            printf("Queue is full.\n");
        }
    }
    printf("\nGET\n");
    while (!isEmpty(&q))
    {
        printf("get %d:\n",get(&q));
        if (!isEmpty(&q))
        {
            displayQueue(&q);
        }
        else
        {
            printf("Queue is empty.\n");
        }
    }
    return 0;
}