#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n, int *comps, int *shifts)
{
    *comps = 0, shifts = 0;
    int i, j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] < key)
        {
            (*comps)++;
            (*shifts)++;
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

}


void main(){
	int n = 5;
	int arr[10] = {12, 11, 13, 5, 6};
    printf("Mang ban dau: ");
    printArray(arr, n);
    insertionSort(arr,n);
}
