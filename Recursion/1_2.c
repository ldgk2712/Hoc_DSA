#include <stdio.h>

float g(int n)
{
    if (n == 1)
        return 1.0;
    return n * n + g(n - 1);
}

int main()
{
    int n;
    scanf("%d",&n);
    float sum = 1.0;
    for (int i = 2; i <= n; i++)
    {
        sum = sum + i*i;
    }
    printf("De Quy: %.2f\n",g(n));
    printf("Khong De Quy: %.2f\n",sum);
}