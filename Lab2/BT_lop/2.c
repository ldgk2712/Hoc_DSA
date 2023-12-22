#include <stdio.h>

void linearSearch(int a[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
        {
            printf("%d\n",i);
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

    linearSearch(a,n,value);

    return 0;
}