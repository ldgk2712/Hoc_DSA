#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int data;
    struct NodeType* next;
} Node;

typedef struct LinkedListType
{
    Node *head;
} LinkedList;

void init(LinkedList *list)
{
    list->head = NULL;
}

Node *makeNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertHead(int data, LinkedList *list)
{
    Node *node = makeNode(data);
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

void deleteHead(LinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *node = list->head->next;
    list->head = node;
}

void insertTail(int data, LinkedList *list)
{
    Node *node = makeNode(data);
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        Node *tmp = list->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void deleteTail(LinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *cur = list->head;
    Node *pre = NULL;
    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    if (pre == NULL)
    {
        free(cur);
        list->head = NULL;
    }
    else
    {
        free(cur);
        pre->next = NULL;
    }
}

void printList(LinkedList *list)
{
    Node *node = list->head;
    while (node != NULL)
    {
        printf("Node address: %p |", &(node->data));
        printf("data = %d |", node->data);
        printf("Next node address: %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    LinkedList list;
    init(&list);
    int arr[8] = {2, 12, 9, 0, 11, 3, 4, 8};
    // int n = sizeof(arr)/sizeof(arr[0]); 
    for (int i = 0; i < 8; i++)
    {
        insertTail(arr[i], &list);
    }

    insertHead(19,&list);
    printList(&list);

    insertTail(-3,&list);
    printList(&list);

    deleteHead(&list);
    printList(&list);

    deleteTail(&list);
    printList(&list);

    return 0;
}