#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int data;
    struct NodeType* next;
} Node;

typedef struct LinkedListType_Queue
{
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

Node* makeNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void put(Queue* q, int value)
{
    Node* node = makeNode(value);
    if (q->tail == NULL) {
        q->head = q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
}

int get(Queue* q)
{
    if (q->head == NULL) {
        return -1;
    }
    int value = q->head->data;
    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    if (q->head == NULL) {
        q->tail = NULL;
    }
    return value;
}

void printQueue(Queue* q)
{
    Node* node = q->head;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);

    int a[] = {32, 20, 11, -25, -42};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        put(&q, a[i]);
    }

    printf("Hang doi sau khi them phan tu:\n");
    printQueue(&q);

    int val = get(&q);
    printf("Phan tu o dau hang doi hien tai: %d\n", val);

    printf("Hang doi sau khi loai bo phan tu:\n");
    printQueue(&q);

    return 0;
}
