#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void searchIndex(float a[], int n, int m)
{
    float nearValue = fabs(m - a[0]);
    for (int i = 1; i < n; i++)
    {
        if (nearValue > fabs(m-a[i]))
        {
            nearValue = fabs(m-a[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nearValue == fabs(m-a[i]))
        {
            printf("%.2f at index %d nearest to %d\n", a[i], i, m);
        }
    }
}


int main()
{
    int n, m;
    float a[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&a[i]);
    }
    scanf("%d",&m);

    searchIndex(a,n,m);
    return 0;
}