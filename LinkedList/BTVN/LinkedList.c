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

void insertHead(LinkedList *list, int data)
{
    Node *node = makeNode(data);
    if (list->head == NULL)
    {
        list->head = node;
        return;
    }
    node->next = list->head;
    list->head = node;
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

void insertTail(LinkedList *list, int data)
{
    Node *node = makeNode(data);
    if (list->head == NULL)
    {
        list->head = node;
        return;
    }
    Node *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

void deleteTail(LinkedList *list)
{
    Node *currNode = list->head;
    Node *prevNode = NULL;
    if (list->head == NULL)
    {   
        return;
    }
    while (currNode->next != NULL)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (prevNode == NULL)
    {
        free(currNode);
        list->head = NULL;
        return;
    }
    free(currNode);
    prevNode->next = NULL;
}

void insertNodeAtPosition(LinkedList *list, int data, int pos)
{
    Node *node = makeNode(data);

    if (list->head == NULL || pos == 1)
    {
        node->next = list->head;
        list->head = node;
        return;
    }

    Node *temp = list->head;
    for (int i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        free(temp);
        return;
    }
    node->next = temp->next;
    temp->next = node;
}

void deleteNodeAtPosition(LinkedList *list, int pos)
{
    if (list->head == NULL)
    {
        return;
    }
    
    Node *temp = list->head;
    for (int i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL)
    {
        free(temp);
        return;
    }
    temp->next = temp->next->next;
}

// chèn vào ds giảm dần
void insert(LinkedList *list, int val)
{
    Node *node = makeNode(val);
    if (list->head == NULL || list->head->data < val)
    {
        node->next = list->head;
        list->head = node;
        return;
    }
    Node *temp = list->head;
    while (temp->next != NULL && temp->next->data > val)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}

// xóa val của ds tăng dần
void delete(LinkedList *list, int val)
{
    if (list->head == NULL || list->head->data > val)
    {
        return;
    }

    Node *currNode = list->head;
    Node *prevNode = NULL;
    
    if (currNode->data == val)
    {
        list->head = currNode->next;
        free(currNode);
        return;
    }

    while (currNode != NULL && currNode->data != val)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL)
    {
        return;
    }

    prevNode->next = currNode->next;
    free(currNode);
}

void printList(LinkedList *list)
{
    Node *node = list->head;
    while (node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    LinkedList list;
    init(&list);

    int a[] = {32, 20, 11, -25, -42};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        insertHead(&list, a[i]);
    }
    printList(&list);
    delete(&list, 11);
    printList(&list);
    return 0;
}