#include <stdio.h>
#include <stdlib.h>

// Hàm sinh mảng số ngẫu nhiên
void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

// Hàm swap
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Hàm average
float average(int arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum/n;
}

int linearSearch(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int value)
{
    int l = 0;
    int r = n-1;
    while (l < r)
    {
        int m = (l+r)/2;
        if (value < arr[m])
        {
            r = m-1;
        }
        else if (value > arr[m])
        {
            l = m+1;
        }
        else 
        {
            return m;
        }
    }
    return -1;
}

void insertArray(int arr[], int *n, int value, int index)
{
    if (index < 0 || index > *n)
    {
        return;
    }
    for (int i = *n; i > index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    (*n)++;
}

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

int main()
{
    int arr[100], n, min, max;
    time_t t;
    srand((unsigned)time(&t));
    printf("\n");
    initializeArray(arr,n,min,max);
    return 0;
}