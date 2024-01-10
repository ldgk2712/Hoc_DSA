#include <stdio.h>

float sumA(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return sumA(n-1) + (float)1/n;
}

float sumB(int n)
{
    if (n == 1)
    {
        return 0.5;
    }
    return sumB(n-1) + (float)1/(2*n);
}

float sumC(int n)
{
    if (n == 1)
    {
        return 0.5;
    }
    return sumC(n-1) + (float)n/(n+1);
}

int sumD(int n)
{
    if (n <= 1)
    {
        return n+2;
    }
    return 6*sumD(n-1) - 9*sumD(n-2);
}

int main()
{
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",sumD(i));
    }
    return 0;
}