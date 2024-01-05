#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n, int *comps, int *swaps)
{
    (*comps) = 0, (*swaps) = 0;
    for (int i = 0; i < n-1; i++)
    {
        
        int minIdx = i;
        for (int j = i+1; j < n; j++)
        {
            (*comps)++;
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            (*swaps)++;
            swap(&arr[i],&arr[minIdx]);
        }
    }
}

int main()
{
    int arr[15] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int swaps, comps;
    printf("unsorted: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    selectionSort(arr,15,&comps,&swaps);
    printf("sorted: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Comps: %d\n",comps);
    printf("Swaps: %d\n",swaps);
    return 0;
}