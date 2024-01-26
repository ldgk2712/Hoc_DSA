#include <stdio.h>

// u(n) = n*(n+1)

int S(int n)
{
    if (n == 1) return 2;

    return S(n-1) + n*(n+1);
}

// B1: BASE CASE xay ra khi n = 1
// if (n == 1)
//     return 1*2;
// B2: Ket qua cua BASE CASE: S(1) = 1*2 = 2;
// B3: Truoc BASE CASE: n = 2
// S(2) = S(1) + 2*3 = 1*2 + 2*3 = 8
// B4: Truoc case B3: n = 3
// S(3) = S(2) + 3*4 = S(1) + 2*3 + 3*4 = 1*2 + 2*3 + 3*4 = 20

int S1(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i*(i+1);
    }
    return sum;
}

int main()
{
    int n = 100;
    printf("Ham S(%d) = %d\n",n,S(n));
    printf("Ham S1(%d) = %d\n",n,S1(n));
    return 0;
}