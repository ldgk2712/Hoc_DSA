#include <stdio.h>

void insertOrderedArray(int a[], int *n, int value)
{
    int i = *n;
    while (i > 0 && value < a[i-1])
    {
        a[i] = a[i-1];
        i--;
    }
    a[i] = value;
    (*n)++;
    
    for (int j = 0; j < *n; j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");
}

int main()
{
    int a[100], n, value;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&value);
    insertOrderedArray(a,&n,value);
    return 0;
}