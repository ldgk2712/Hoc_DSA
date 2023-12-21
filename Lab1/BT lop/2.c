#include <stdio.h>

void insertArray(int a[], int *n, int value, int index)
{
    for (int i = *n; i > index; i--)
    {
        a[i] = a[i-1];
    }
    a[index] = value;
    (*n)++;
}

int main() {
    int n;
    int a[100];
    int value;
    int index;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d %d",&value,&index);
    insertArray(a, &n, value, index);
    

    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}