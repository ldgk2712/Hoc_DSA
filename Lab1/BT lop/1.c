#include <stdio.h>

int searchArray(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (value == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    int arr[100];
    int value;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&value);
    
    int index = searchArray(arr, n, value);
    if (index == -1)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("Found %d at %d",value,index);
    }
}