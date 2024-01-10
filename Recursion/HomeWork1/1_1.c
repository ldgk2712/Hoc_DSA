#include <stdio.h>

int f(int n)
{
    if (n == 1)
        return 1;
    return f(n-1)*2;
}

int main()
{
    int n;
    scanf("%d",&n);
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum *= 2;
    }
    printf("De Quy: %d\n",f(n));
    printf("Khong De Quy: %d\n",sum);
}