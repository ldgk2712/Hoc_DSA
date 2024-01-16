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
    free(list->head);
    list->head = node;
}

void insertTailRecursive(Node *node, int data)
{
    if (node->next == NULL)
    {
        Node *newNode = makeNode(data);
        node->next = newNode;
        return;
    }
    insertTailRecursive(node->next, data);
}

void insertTail(LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        list->head = makeNode(data);
        return;
    }
    insertTailRecursive(list->head, data);
}

void deleteTailRecursive(Node *prevNode, Node *currNode)
{
    if (currNode->next == NULL)
    {
        free(currNode);
        prevNode->next = NULL;
        return;
    }
    deleteTailRecursive(currNode, currNode->next);
}

void deleteTail(LinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }

    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
        return;
    }

    deleteTailRecursive(list->head, list->head->next);
}

void insertNodeAtPositionRecursive(Node *node, int data, int pos, int currentPos)
{
    if (node == NULL)
    {
        return;
    }

    if (currentPos + 1 == pos)
    {
        Node *newNode = makeNode(data);
        newNode->next = node->next;
        node->next = newNode;
        return;
    }

    insertNodeAtPositionRecursive(node->next, data, pos, currentPos + 1);
}

void insertNodeAtPosition(LinkedList *list, int data, int pos)
{
    if (list->head == NULL || pos == 1)
    {
        insertHead(list, data);
        return;
    }

    insertNodeAtPositionRecursive(list->head, data, pos, 1);
}

void deleteNodeAtPositionRecursive(Node *node, int pos, int currentPos)
{
    if (node == NULL || node->next == NULL)
    {
        return;
    }

    if (currentPos + 1 == pos)
    {
        Node *temp = node->next;
        node->next = node->next->next;
        free(temp);
        return;
    }

    deleteNodeAtPositionRecursive(node->next, pos, currentPos + 1);
}

void deleteNodeAtPosition(LinkedList *list, int pos)
{
    if (list->head == NULL)
    {
        return;
    }

    if (pos == 1)
    {
        deleteHead(list);
        return;
    }

    deleteNodeAtPositionRecursive(list->head, pos, 1);
}

void printListRecursive(Node *node)
{
    if (node == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ", node->data);
    printListRecursive(node->next);
}

void printList(LinkedList *list)
{
    printListRecursive(list->head);
}

int main()
{
    LinkedList list;
    init(&list);

    int a[] = {32, 20, 11, -25, -42};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        insertHead(&list, a[i]);
    }
    printf("Danh sach:\n");
    printList(&list);

    deleteNodeAtPosition(&list, 3);
    printf("Danh sach sau khi xoa phan tu thu 3:\n");
    printList(&list);

    insertNodeAtPosition(&list, 100, 2);
    printf("Danh sau sau khi them val = 100 vao vi tri thu 2:\n");
    printList(&list);

    deleteTail(&list);
    printf("Danh sach sau khi xoa phan tu cuoi cung:\n");
    printList(&list);

    return 0;
}
