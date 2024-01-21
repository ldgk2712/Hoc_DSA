#include <stdio.h>

// u(n) = 1/(n + (n-1))

float S(int n)
{
    if (n == 1) return 1.0;

    return S(n-1) + 1.0/(n + (n-1));
}

// B1: BASE CASE xay ra khi n = 1
// if (n == 1)
//     return 1;
// B2: Ket qua cua BASE CASE: S(1) = 1;
// B3: Truoc BASE CASE: n = 2
// S(2) = S(1) + 1/3 = 1 + 1/3
// B4: Truoc case B3: n = 3
// S(3) = S(2) + 1/5 = S(1) + 1/3 + 1/5 = 1 + 1/3 + 1/5

float S1(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0/(i + (i-1));
    }
    return sum;
}

int main()
{
    int n = 10;
    printf("Ham S(%d) = %f\n",n,S(n));
    printf("Ham S1(%d) = %f\n",n,S1(n));
    return 0;
}