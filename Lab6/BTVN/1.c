#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int top;
    char *str;
} Stack;

void init(Stack *s, int len)
{
    s->top = -1;
    s->str = (char *)malloc(len * sizeof(char));
    if (s->str == NULL)
    {
        // Xử lý khi cấp phát bộ nhớ thất bại
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s, int len)
{
    return s->top == len - 1;
}

void push(Stack *s, char ch)
{
    if (isFull(s, strlen(s->str)))
    {
        // Nếu ngăn xếp đầy, cần cấp phát thêm bộ nhớ
        int newSize = 2 * strlen(s->str); // Được giả định cho việc cấp phát thêm
        s->str = (char *)realloc(s->str, newSize * sizeof(char));
        if (s->str == NULL)
        {
            // Xử lý khi cấp phát bộ nhớ thất bại
            fprintf(stderr, "Memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    s->str[++(s->top)] = ch;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->str[(s->top)--];
}

void reverseStack(char *str)
{
    int len = strlen(str);
    Stack s;
    init(&s, len);

    for (int i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }

    printf("RevereString - Stack: ");
    while (!isEmpty(&s))
    {
        printf("%c", pop(&s));
    }
    printf("\n");

    // Không cần giải phóng bộ nhớ ở đây vì đã giải phóng trong hàm main
}

void reverseArr(char *str)
{
    printf("ReverseString - Array: ");
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main()
{
    char s[100];
    fgets(s, sizeof(s), stdin);
    if (s[strlen(s) - 1] == '\n')
    {
        s[strlen(s) - 1] = '\0';
    }
    reverseArr(s);
    reverseStack(s);

    // Giải phóng bộ nhớ
    free(s);

    return 0;
}
