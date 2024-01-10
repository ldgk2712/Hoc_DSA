#include <stdio.h>

int P(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return 3;
    return P(n-1)*P(n-3);
}


int main()
{
    int n;
    scanf("%d",&n);
    int sum = 1;
    if (n <= 2)
    {
        sum = n+1;
    }

    int f0 = 1;
    int f1 = 2;
    int f2 = 3; 

    for (int i = 3; i <= n; i++)
    {
        sum = f2 * f0;
        f0 = f1;
        f1 = f2;
        f2 = sum;
    }
    printf("De Quy: %d\n",P(n));
    printf("Khong De Quy: %d\n",sum);
}