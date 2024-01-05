#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch (int arr[], int n, int value, int *comps)
{
    *comps = 0;
    for (int i = 0; i < n; i++)
    {
        (*comps)++;
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
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
    int min = -10*n;
    int max = 10*n;
    initializeArray(arr, n, min, max);
    float sum = 0;
    for (int i = 0; i < k; i++)
    {
        int value = arr[rand() % 20]; // phần tử bất kì thuộc mảng
        int comps;
        linearSearch(arr, n, value, &comps);
        fre[comps]++;
        sum += comps;
    }
    return sum/k;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[20], n = 20;
    int k[5] = {10, 20, 100, 1000, 10000};
    for (int i = 0; i < 5; i++)
    {
        printf("k = %d\n",k[i]);
        int fre[21] = {0};
        float a = average(arr,n,k[i],fre);
        for (int j = 1; j < 21; j++)
        {
            printf("%d\t", j);
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
