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

// chèn vào ds giảm dần
void insert(LinkedList *list, int val)
{
    // Tạo node cần chèn
    Node *node = makeNode(val);

    // TH danh sách rỗng hoặc node đầu danh sách bé hơn value
    if (list->head == NULL || list->head->data < val)
    {
        node->next = list->head;
        list->head = node;
        return;
    }

    // Tạo node duyệt phần tử
    Node *curr = list->head;

    // Duyệt đến trước node nhỏ hơn bằng val
    while (curr->next != NULL && curr->next->data > val)
    {
        curr = curr->next;
    }

    // Chèn node vào vị trí phù hợp
    node->next = curr->next;
    curr->next = node;
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
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void createNewList(LinkedList *list, LinkedList *newList)
{
    // Tạo danh sách mới
    init(newList);

    // Tọa node duyệt các node trong danh sách cũ
    Node *curr = list->head;
    while (curr != NULL)
    {
        // Tạo node kiểm tra phần tử trùng
        Node *check = newList->head;
        // Tạo biến kiểm tra bị trùng
        int key = 0;

        while (check != NULL)
        {
            if (check->data == curr->data)
            {
                // Phần tử bị trùng thì đánh dấu và dừng lại
                key = 1;
                break;
            }
            check = check->next;
        }

        // Không trùng thì chèn vào danh sách mới
        if (!key)
        {
            insert(newList, curr->data);
        }

        // Chuyển đến node tiếp theo
        curr = curr->next;
    }
}

// Recursion
Node *getTail(Node *head)
{
    // Nếu danh sách rỗng
    if (head == NULL) return NULL;
    // Nếu danh sách chỉ có 1 phần tử
    if (head->next == NULL) return head;
    // Trả về phần tử kế tiếp cho đến cuối danh sách
    return getTail(head->next);
}

Node *printListRecursion(Node *head)
{
    // Nếu danh sách rỗng
    if (head == NULL)
    {
        return NULL;
    }
    // Nếu danh sách khong rỗng
    printf("%d ",head->data);
    // Trả về phần tử kế tiếp
    return printListRecursion(head->next);
}

void reversePrint(Node *node)
{
    // Nếu node là NULL thì hàm dừng
    if (node == NULL)
        return;

    // BEFORE BASCASE
    // Chạy đến node tiếp theo
    reversePrint(node->next);

    // AFTER BASECASE
    // In ra node hiện tại
    printf("%d ", node->data);
}

void deleteList(Node *node)
{
    // Nếu node là NULL thì hàm dừng
    // basecase
    if (node == NULL)
    {
        return;
    }

    // before basecase
    // duyệt đến node kế tiếp 
    deleteList(node->next);

    // after basecase
    // Xóa node hiện tại
    free(node);
}

int main()
{
    LinkedList list;
    init(&list);

    for (int i = 0; i < 20; i++)
    {
        int value = rand() % 10;
        insertHead(value,&list);
    }

    printf("Danh sach cu: ");
    printList(&list);
    reversePrint(list.head);

    // printf("%d",getTail(list.head)->data);

    return 0;
}