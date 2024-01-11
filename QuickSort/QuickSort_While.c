#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}            

int partition(int a[], int left, int right, int *shiftLeft, int *shiftRight) {
    int pivot = right;
    right--;
    while (1)
    {
        while (a[left] < a[pivot])
        {
            left++;
        }
        while (a[right] > a[pivot])
        {
            right--;
        }
        if (left < right)
        {
            swap(&a[left],&a[right]);
        }
        swap(&a[left],&a[pivot]);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot_index = partition(a,left,right);
        quickSort(a, left, pivot_index-1);
        quickSort(a, pivot_index+1, right);
    }
}

int main() {
    int a1[] = {1, 3, 7, 8, 5};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    printf("Original array: ");
    printArray(a1, n1);
    quickSort(a1, 0, n1 - 1);
    printf("Sorted array: ");
    printArray(a1, n1);
    printf("\n");
    
    int a2[] = {0, 2, 3, 9, 5, 6, 8, 4};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    printf("Original array: ");
    printArray(a2, n2);
    quickSort(a2, 0, n2 - 1);
    printf("Sorted array: ");
    printArray(a2, n2);
    printf("\n");

    int a3[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(a3) / sizeof(a3[0]);
    printf("Original array: ");
    printArray(a3, n3);
    quickSort(a3, 0, n3 - 1);
    printf("Sorted array: ");
    printArray(a3, n3);
    printf("\n");

    return 0;
}
