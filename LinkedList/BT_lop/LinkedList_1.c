#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    /* data */
    int data;
    struct NodeType *next;
} Node;

typedef struct LinkedListType
{
    Node *head;
} LinkedList;

void init(LinkedList *list)
{
    list->head = NULL;
}

Node* makeNode(int data)
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

void printList(LinkedList *list)
{
    Node *node = list->head;
    while (node != NULL)
    {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d | ",node->data);
        printf("Next node address: %p\n",node->next);
        node = node->next;
    }
    printf("\n");
}

void deleteHead(LinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *node = list->head->next;
    list->head = node;
    free(node);
}

int main()
{
    LinkedList list;
    init(&list);
    for (int i = 0; i < 10; i++)
    {
        insertHead(i, &list);
    }
    printList(&list);

    printf("After insert 15:\n");
    insertHead(15,&list);
    printList(&list);

    printf("After delete head:\n");
    deleteHead(&list);
    printList(&list);
    return 0;
}