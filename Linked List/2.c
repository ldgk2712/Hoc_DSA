#include <stdio.h>
#include <stdlib.h>

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

//Định nghĩa Linked list
typedef struct LinkedListType{
    Node* head;
}LinkedList;

//Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Hàm chèn node mới vào đầu danh sách
void insertHead(int data, LinkedList* list){
    Node *newNode = makeNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
}

//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}

// Hàm xóa phần tử đầu ra khỏi ds
void deleteHead(LinkedList* list){
    if (list->head == NULL)
    {
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

// Hàm xóa phần tử cuối ra khỏi ds
void deleteTail(LinkedList* list)
{
    if (list->head == NULL)
    {
        return;
    }
    Node *curNode = list->head;
    Node *preNode = NULL;

    // Di chuyển đến phần tử cuối cùng
    while (curNode->next != NULL)
    {
        preNode = curNode;
        curNode = curNode->next;
    }

    if (preNode == NULL) {
        // Danh sách chỉ có một phần tử
        free(curNode);
        list->head = NULL;
    } else {
        // Xoá phần tử cuối cùng và cập nhật con trỏ next của phần tử trước nó
        free(curNode);
        preNode->next = NULL;
    }
}

// Hàm chèn phần tử vào cuối ds
void insertTail(int data, LinkedList* list) {
    Node* newNode = makeNode(data);

    if (list->head == NULL) {
        // Danh sách rỗng, chèn vào đầu danh sách
        list->head = newNode;
    } else {
        // Tìm phần tử cuối cùng và chèn vào sau nó
        Node* currentNode = list->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

//Hàm main
int main(){
    LinkedList list;
    init(&list);

    int arr[8] = {2, 12, 9, 0, 11, 3, 4, 8};
    for (int i = 7; i >= 0; i--)
    {
        insertHead(arr[i], &list);
    }
    printList(&list);

    printf("After insert:\n");
    insertHead(19, &list);
    insertTail(-3, &list);
    printList(&list);

    printf("After delete:\n");
    deleteHead(&list);
    deleteTail(&list);
    printList(&list);
    return 0;
}
