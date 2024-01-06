#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deleteArray(int arr[], int *n, int index)
{
    if (index < 0 || index > *n)
    {
        return;
    }
    for (int i = index; i < *n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    (*n)--;
}


void caseA(int arr[], int *n, int k)
{
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] >= k)
        {
            int idx = i;
            deleteArray(arr, n, idx);
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void caseB(int arr[], int *n, int k)
{
    bubbleSort(arr, *n);
    int idx = *n;
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] >= k)
        {
            idx = i;
            break;
        }
    }
    *n = idx;
}

void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int arr[10], n = 10;
    initializeArray(arr,n,1998,2023);
    int k = 2016;

    printf("Original Array:\n");
    printArray(arr,n);

    printf("After CaseA:\n");
    caseA(arr, &n, k);
    printArray(arr,n);

    printf("After CaseB:\n");
    caseB(arr, &n, k);
    printArray(arr, n);

}