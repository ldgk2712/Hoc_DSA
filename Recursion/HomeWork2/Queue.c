#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

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

void get(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack is empty!\n");
        return;
    }
    q->head++;
    get(q);
}

void displayQueue(Queue *q)
{
    for (int i = q->head; i <= q->tail; i++)
    {
        printf("%d ",q->a[i]);
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
    Queue q;
    init(&q);
    time_t t;
    srand((unsigned)time(&t));
    int arr[20];
    initializeArray(arr,20,-10,10);
    for (int i = 0; i < 20; i++)
    {
        put(&q, arr[i]);
    }
    displayQueue(&q);
    get(&q);
    return 0;
}