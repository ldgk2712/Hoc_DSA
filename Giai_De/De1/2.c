#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa node
typedef struct NodeType
{
    char data;
    struct NodeType* next;
} Node;

// Định nghĩa Linkedlist
typedef struct LinkedListType
{
    Node *head;
} LinkedList;

// Khởi tại Linkedlist
void init(LinkedList *list)
{
    list->head = NULL;
}

// Tạo node mới
Node *makeNode(char data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Chèn kí tự vào cuối list
void insertTail(LinkedList *list, char data)
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

// Hàm in list
void printList(LinkedList *list)
{
    Node *node = list->head;
    while (node != NULL)
    {
        printf("%c",node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    LinkedList list;
    init(&list);

    char arr[] = "DSATTHS12023";
    for (int i = 0; i < strlen(arr); i++)
    {
        insertTail(&list,arr[i]);
    }
    printList(&list);

    return 0;
}