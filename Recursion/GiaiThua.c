#include <stdio.h>

int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }
    return number * factorial(number - 1);
}

int main()
{
    printf("5! = %d\n",factorial(5));
    return 0;
}