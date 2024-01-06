#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minIndex(float arr[], int n, int *assgins)
{
    float minVal = arr[0];
    int minIdx = 0;
    *assgins = 0;
    for (int i = 1; i < n; i++)
    {
        if (minVal > arr[i])
        {
            (*assgins)++;
            minVal = arr[i];
            minIdx = i;
        }
    }
}

void initializeArray(float arr[], int n, float min, float max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

float average(float arr[], int n, int k, int fre[])
{
    float min = -2.0*n;
    float max = 2.0*n;
    initializeArray(arr, n, min, max);
    float sum = 0;
    for (int i = 0; i < k; i++)
    {
        int assgins;
        minIndex(arr, n, &assgins);
        fre[assgins]++;
        sum += assgins;
    }
    return sum / k;
}
int main()
{
    time_t t;
    srand((unsigned)time(&t));
    float arr[20];
    int n = 20;
    int k[5] = {10, 20, 50, 100, 1000};

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