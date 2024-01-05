#include <stdio.h>

void linearSearch(int a[], int n, int value)
{
    int stepLinear = 0;
    for (int i = 0; i < n; i++)
    {
        stepLinear++;
        if (a[i] == value)
        {
            printf("%d\n",stepLinear);
            return;
        }
    } 
    printf("%d\n",stepLinear);
}

void binarySearch(int a[], int n, int value)
{
    int l = 0;
    int r = n-1;
    int stepBinary = 0;
    while (l < r)
    {
        int m = (l+r)/2;
        stepBinary++;
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
            printf("%d\n",stepBinary);
            return;
        }
    }
    printf("%d\n",stepBinary);
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

    linearSearch(a,n,value);
    binarySearch(a,n,value);

    return 0;
}