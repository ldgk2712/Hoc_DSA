#include <stdio.h>

void binarySearch(int a[], int n, int value)
{
    int l = 0;
    int r = n-1;
    while (l < r)
    {
        int m = (l+r)/2;
        if (a[m] > value)
        {
            r = m-1;
        }
        else if (a[m] < value)
        {
            l = m+1;
        }
        else 
        {
            printf("%d\n",m);
            return;
        }
    }
    printf("Not found!\n");
}

int main()
{
    int n, a[100], value;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&value);

    binarySearch(a,n,value);

    return 0;
}