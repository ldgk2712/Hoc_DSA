#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20

typedef struct {
    int top;
    int cards[MAX_CARDS];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int cardNumber) {
    if (s->top < MAX_CARDS - 1) {
        s->top++;
        s->cards[s->top] = cardNumber;
    }
}

/*
Hàm tạo hộp lưu số của các thẻ:
Base case (Bước 1):

Base case là khi randomCard bằng 1. Khi này, thêm thẻ số 1 vào hộp và kết thúc hàm.
Result of base case (Bước 2):

Kết quả ứng với base case là thêm thẻ số 1 vào hộp (push(s, 1);).
Before base case (Bước 3):

Trước khi đến base case, hàm gọi chính nó với rand() % 10 + 1 để tạo ngẫu nhiên số tiếp theo và thêm vào hộp.
Before before (Bước 4):

Bước 4 là gọi đệ quy để tiếp tục quá trình tạo hộp với số tiếp theo.
*/

void createBox(Stack *s, int randomCard) {
    if (randomCard == 1) {
        push(s, 1);
        return;
    }

    createBox(s, rand() % 10 + 1);
}

/*
Hàm tính tổng số các thẻ trong hộp:
Base case (Bước 1):

Base case là khi stack rỗng (isEmpty(s)). Trong trường hợp này, trả về 0.
Result of base case (Bước 2):

Kết quả ứng với base case là 0.
Before base case (Bước 3):

Trước khi đến base case, hàm lấy giá trị của thẻ vừa pop ra (int poppedCard = s->cards[s->top];) và giảm chỉ số đỉnh của stack.
Before before (Bước 4):

Bước 4 là gọi đệ quy để tính tổng với các thẻ còn lại trong hộp.
*/

int calculateTotal(Stack *s) {
    if (isEmpty(s)) {
        return 0;
    }

    int poppedCard = s->cards[s->top];
    s->top--;

    return poppedCard + calculateTotal(s);
}

int main() {
    srand(time(NULL)); // Khởi tạo seed cho hàm rand()

    Stack cardBox;
    initStack(&cardBox);

    createBox(&cardBox, rand() % 10 + 1);

    int totalCards = calculateTotal(&cardBox);

    printf("Total number of cards in the box: %d\n", totalCards);

    return 0;
}
