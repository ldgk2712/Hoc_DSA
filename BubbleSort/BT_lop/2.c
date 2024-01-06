#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
        // Sinh số ngẫu nhiên giá trị trong khoảng [min, max]
    }
}

void bubbleSort(int arr[], int n, int* comps, int* swaps)
{
    *comps = 0, *swaps = 0;
    for (int i = 0; i < n-1; i++)   
    {
        for (int j = 0; j < n-1-i; j++)
        {
            (*comps)++;
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                (*swaps)++;
            }
        }
    }
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int arr[10], n = 10;
    int k[6] = {10, 25, 50, 100, 1000, 10000};
    printf("Size of array: %d\n",n);
    for (int i = 0; i < 6; i++)
    {
        printf("k = %d\n",k[i]);

        float sum_comps = 0, sum_swaps = 0;
        int cps[10001] = {0};
        int sps[10001] = {0};
        for (int j = 0; j < k[i]; j++)
        {
            int comps, swaps;
            initializeArray(arr,n,-100,100);
            bubbleSort(arr, n, &comps, &swaps);
            cps[j] = comps;
            sps[j] = swaps;
            sum_comps += comps;
            sum_swaps += swaps;
        }

        printf("\nBang so lieu: \nObservation\t\tcomps\t\t\tswaps");

        for(int j = 0; j < k[i]; j++){

            printf("\n%d\t\t\t%d\t\t\t%d", j+1, cps[j], sps[j]);

        }

        printf("\nAverage Comps: %.3f\n",sum_comps / k[i]);
        printf("Average Swaps: %.3f\n\n",sum_swaps / k[i]);
    }

    return 0;
}
