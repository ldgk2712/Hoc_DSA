#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(float arr[], int n, float min, float max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

int minIndex(float arr[], int start, int n, int *comps) {
    float minVal = arr[start];
    int minIdx = start;
    *comps = 0;
    for (int i = start + 1; i < n; i++) {
        (*comps)++;
        if (minVal > arr[i]) {
            minVal = arr[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(float arr[], int n, int *comps) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = minIndex(arr, i, n, comps);
        swap(&arr[i], &arr[minIdx]);
    }
}

float average(float arr[], int n, int k, int fre[], int *totalComparisons) {
    float sum = 0;
    for (int i = 0; i < k; i++) {
        int comps = 0;
        selectionSort(arr, n, &comps);
        fre[comps]++;
        sum += comps;
        *totalComparisons += comps;
    }
    return sum / k;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    float arr[40];
    int n = 40;

    int fre[41] = {0};
    int totalComparisons = 0;
    float a = average(arr, n, n, fre, &totalComparisons);

    printf("Comparisons Frequency:\n");
    printArray(fre + 1, n - 1); // In từ chỉ số 1 đến n-1
    printf("Average: %.3f\n", a);
    printf("Total Comparisons: %d\n", totalComparisons);

    return 0;
}
