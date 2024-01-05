#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertZero(int a[], int *n, int position) {
    (*n)++;
    for (int i = (*n) - 1; i > position; i--)
        a[i] = a[i - 1];
    a[position] = 0;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%5d", a[i]);
    printf("\n");
}

void f(int a[], int *n, int *swaps, int *inserts) {
    *swaps = 0, *inserts = 0;
    int min = 0;
    int j;
    for (int i = 0; i < (*n); i++) {
        printf("i = %d\n", i);
        if (i % 2 == 0) {
            for (j = i; j < (*n); j++) {
                if (a[j] % 2 == 0) {
                    if (a[min] % 2 != 0 || a[min] > a[j] || min < i)
                        min = j;
                }
            }

            if (a[min] % 2 == 0) {
                (*swaps)++;
                swap(&a[i], &a[min]);
            } else {
                (*inserts)++;
                insertZero(a, n, i);
            }
        } else {
            for (j = i; j < (*n); j++) {
                if (a[j] % 2 != 0) {
                    if (a[min] % 2 == 0 || a[min] > a[j] || min < i)
                        min = j;
                }
            }

            if (a[min] % 2 != 0) {
                (*swaps)++;
                swap(&a[i], &a[min]);
            } else {
                (*inserts)++;
                insertZero(a, n, i);
            }
        }

        printArray(a, *n);
    }
}

int main() {
    int a[] = {1, 9, 7, 5, 2, 4};
    int n = 6;
    int swaps = 0, inserts = 0;
    printf("Before: ");
    printArray(a, n);
    f(a, &n, &swaps, &inserts);
    printf("After: ");
    printArray(a, n);
    printf("Swaps: %d\n", swaps);
    printf("Inserts: %d\n", inserts);
    return 0;
}
