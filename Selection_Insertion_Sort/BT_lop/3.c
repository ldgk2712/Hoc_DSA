#include <stdio.h>

void insertionSort(int arr[], int n) {
    int comps = 0;  // Số bước so sánh
    int shifts = 0; // Số bước dời

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comps++; // Tăng số bước so sánh
            arr[j + 1] = arr[j];
            j--;
            shifts++; // Tăng số bước dời
        }

        arr[j + 1] = key;

        // In giá trị của comps, shifts sau từng vòng
        printf("Vòng %d: comps=%d, shifts=%d\n", i, comps, shifts);
    }

    // In tổng số bước comps, shifts
    printf("\nTổng số bước: comps=%d, shifts=%d\n", comps, shifts);
}

int main() {
    int arr[] = {5, 4, 3, 2, 1}; // Dãy đảo ngược
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
