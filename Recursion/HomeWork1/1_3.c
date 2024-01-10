#include <stdio.h>

int F(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return F(n-1)+F(n-2);
}


int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    if (n == 1 || n == 2)
    {
        sum = 1;
    }

    int f1 = 1;
    int f2 = 1;

    for (int i = 3; i <= n; i++)
    {
        sum = f1+f2;
        f1 = f2;
        f2 = sum;
    }
    printf("De Quy: %d\n",F(n));
    printf("Khong De Quy: %d\n",sum);
}