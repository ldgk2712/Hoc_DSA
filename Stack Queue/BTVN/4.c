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

void displayQueue(Queue *q)
{
    if(isEmpty(q))
    {
        return;
    }
    printf("Registered users in the queue: ");
    for (int i = q->head; i <= q->tail; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void cancelRegistration(Queue *q, int value)
{
    if (isEmpty(q))
    {
        return;
    }
    
    int found = 0;
    for (int i = q->head; i <= q->tail; i++)
    {
        if (q->items[i] == value)
        {
            found = i;
            break;
        }
    }

    if (found)
    {
        for (int j = found; j < q->tail; j++)
        {
            q->items[j] = q->items[j+1];
        }
        q->tail--;
        printf("User %d has been unregistered.\n", value);
    }
    else
    {
        printf("User %d is not in the queue.\n", value);
    }
}

int main()
{
    Queue eventQueue;
    init(&eventQueue);

    push(&eventQueue, 101);
    push(&eventQueue, 102);
    push(&eventQueue, 103);

    displayQueue(&eventQueue);

    int userToCancel = 102;
    cancelRegistration(&eventQueue, userToCancel);

    displayQueue(&eventQueue);

    int userToRetrieve = get(&eventQueue);
    if (userToRetrieve != -1)
    {
        printf("User %d has joined the event.\n", userToRetrieve);
    }

    return 0;
}