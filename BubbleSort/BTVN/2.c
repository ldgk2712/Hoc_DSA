#include <stdio.h>

int solve1(int arr[], int *n, int *steps)
{
    *steps = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = i+1; j < *n; j++)
        {
            (*steps)++;
            if (arr[j] == arr[i])
            {
                for (int k = j; k < *n-1; k++)
                {
                    arr[k] = arr[k+1];
                }
                (*n)--;
                j--;
            }
        }
    }
    return *steps;
}

int solve2(int arr[], int *n, int *steps)
{
    *steps = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
    }
    int newSize = 1;
    for (int i = 1; i < *n; i++)
    {
       (*steps)++;
        if (arr[i] != arr[i-1])
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    *n = newSize;
    return *steps;
}

int main()
{
    int arr1[] = {3, 5, 2, 8, 5, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int steps1;

    int arr2[] = {3, 5, 2, 8, 5, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int steps2;

    printf("Number of steps for solve1: %d\n", solve1(arr1, &n1, &steps1));
    printf("Number of steps for solve2: %d\n", solve2(arr2, &n2, &steps2));

    printf("Sorted array without duplicates for solve1: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    printf("Sorted array without duplicates for solve2: ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}