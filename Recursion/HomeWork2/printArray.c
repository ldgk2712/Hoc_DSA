#include <stdio.h>

void print(int a[], int n)
{
    if (n == 0)
    {
        printf("%d ",a[0]);
        return;
    }
    print(a, n-1);
    printf("%d ",a[n]);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    print(arr, size);
    return 0;
}