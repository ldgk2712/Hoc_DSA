#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

void bubbleSort(int arr[], int n, int *swaps)
{
    *swaps = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (arr[j-1] > arr[j])
            {
                swap(&arr[j-1],&arr[j]);
                (*swaps)++;
            }
        }
    }
}

float average(int arr[], int n, int k, int fre[])
{
    int min = -10*n;
    int max = 10*n;
    float sum = 0;

    initializeArray(arr, n, min, max);

    for (int i = 0; i < k; i++)
    {
        int swaps;
        bubbleSort(arr, n, &swaps);
        fre[swaps]++;
        sum += swaps;
    }
    return sum/k;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[20], n = 20;
    int k[5] = {10, 50, 100, 1000, 10000};
    for (int i = 0; i < 5; i++)
    {
        printf("k = %d\n",k[i]);
        int fre[401] = {0};
        float a = average(arr, n, k[i], fre);
        for (int j = 1; j < 401; j++)
        {
            printf("%d\t", j);
        }
        printf("\n");
        for (int j = 1; j < 401; j++)
        {
            if (fre[j] != 0)
            {
                printf()
            }
            printf("%d\t",fre[j]);
        }
        printf("\nAverage: %0.3f\n",a);
    }
    return 0;
}