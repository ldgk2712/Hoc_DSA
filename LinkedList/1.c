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
        list->head = node;
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

//Hàm main
int main(){
    LinkedList list;
    init(&list);
    //Tạo danh sách tự động
    for(int i = 0; i < 10; i++)
       insertHead(i, &list); 
    //In danh sách
    printList(&list);
    // Chèn 15 vào đầu ds
    insertHead(15,&list);
    printf("After insert 15:\n");
    printList(&list);
    // Xoá phần tử đầu ds
    deleteHead(&list);
    printf("After delete 15:\n");
    printList(&list);
    return 0;
}
