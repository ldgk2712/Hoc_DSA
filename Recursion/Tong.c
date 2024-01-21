#include <stdio.h>

// B1: BASE CASE xay ra khi n = 1
// if (n == 1)
//     return a[0];
// B2: Ket qua cua BASE CASE: sum(a, 1) = a[0];
// B3: Truoc BASE CASE: n = 2
// sum(a, 2) = sum(a, 1) + a[1] = a[0] + a[1];
// B4: Truoc case B3: n = 3
// sum(a, 3) = sum(a, 2) + a[2] = sum(a, 1) + a[1] = a[0] + a[1];

int sum(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    return sum(a, n-1) + a[n-1];
}

// B1: BASE CASE xay ra khi n = 1
// if (n == 1)
//     return 1;
// B2: Ket qua cua BASE CASE: S1(1) = 1;
// B3: Truoc BASE CASE: n = 2
// S1(2) = S1(1) + 1/2 = 1 + 1/2
// B4: Truoc case B3: n = 3
// S1(3) = S1(2) + 1/3 = S1(1) + 1/2 + 1/3 = 1 + 1/2 + 1/3

float S1(int n)
{
    if (n == 1) return 1;

    return S1(n-1) + 1.0/n;
}

// B1: BASE CASE xay ra khi n = 1
// if (n == 1)
//     return 1/2;
// B2: Ket qua cua BASE CASE: S1(1) = 1/2;
// B3: Truoc BASE CASE: n = 2
// S2(2) = S2(1) + 1/4 = 1/2 + 1/4
// B4: Truoc case B3: n = 3
// S2(3) = S2(2) + 1/3 = S2(1) + 1/2 + 1/3 = 1 + 1/2 + 1/3

float S2(int n)
{
    if (n == 1) return 1.0/2;

    return S2(n-1) + 1.0/(2*n);
}

// B1: BASE CASE xay ra khi n = 1
// if (n == 1)
//     return 1/2;
// B2: Ket qua cua BASE CASE: S1(1) = 1/2;
// B3: Truoc BASE CASE: n = 2
// S2(2) = S2(1) + 1/2 = 1/2 + 2/3
// B4: Truoc case B3: n = 3
// S2(3) = S2(2) + 3/4 = S2(1) + 2/3 + 3/4 = 1/2 + 2/3 + 3/4

float S3(int n)
{
    if (n == 1) return 1.0/2;

    return S3(n-1) + 1.0*n/(n+1);
}

// B1: BASE CASE xay ra khi n = 1 va n = 0
// if (n == 0) return 2;
// if (n == 1) return 3;    
// B2: Ket qua cua BASE CASE: S4(0) = 2, S4(1) = 3
// B3: Truoc BASE CASE: n = 2
// S4(2) = 6*S4(1) - 9*S4(0) = 6*3 - 9*2 = 0
// B4: Truoc case B3: n = 3
// S4(3) = 6*S4(2) - 9*S4(1) = 6*(6*S4(1) - 9*S4(0)) - 9*S4(1) = 6*(6*3 - 9*2) - 9*3 = -27

int S4(int n)
{
    if (n == 0) return 2;
    if (n == 1) return 3;
    return 6*S4(n-1) - 9*S4(n-2);
}


int main(){

    int n;
    scanf("%d",&n);
    printf("S1(%d) = %.2f\n",n,S1(n));
    printf("S2(%d) = %.2f\n",n,S2(n));
    printf("S3(%d) = %.2f\n",n,S3(n));
    printf("S4(%d) = %d\n",n,S4(n));
}