#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void deleteArray(int arr[], int *n, int index, int *assignment)
{
    if (index < 0 || index > *n)
    {
        return;
    }

    *assignment = 1;
    for (int i = index; i < *n-1; i++)
    {
        arr[i] = arr[i+1];
        (*assignment)++;
    }
    (*n)--;
}

void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

float average(int arr[], int n, int k, int fre[])
{
    int min = -100;
    int max = 100;
    initializeArray(arr, n, min, max);
    float sum = 0;

    for (int i = 0; i < k; i++)
    {
        int assignment;
        int index = rand() % n;
        deleteArray(arr, &n, index, &assignment);
        n = SIZE;
        fre[assignment]++;
        sum += assignment;
    }

    return sum/k;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[SIZE], n = SIZE;
    int k[5] = {10, 20, 100, 1000, 10000};

    for (int i = 0; i < 5; i++)
    {
        int fre[21] = {0};
        float a = average(arr, n, k[i], fre);
        printf("k = %d\n", k[i]);
        for (int j = 1; j < 21; j++)
        {
            printf("%d\t",j);
        }
        printf("\n");
        for (int j = 1; j < 21; j++)
        {
            printf("%d\t",fre[j]);
        }
        printf("\nAverage: %0.3f\n",a);
    }
    return 0;
}