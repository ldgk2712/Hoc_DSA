#include <stdio.h>
#include <string.h>

float calculateF(float a, float b, float c)
{
    return a - 2*b - 3*c;
}

void swap(float arr[][3], int x, int y)
{
    float temp[3];
    for (int i = 0; i < 3; i++)
    {
        temp[i] = arr[x][i];
        arr[x][i] = arr[y][i];
        arr[y][i] = temp[i];
    }
}
void bubbleSort(float arr[][3], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (calculateF(arr[j][0], arr[j][1], arr[j][2]) > calculateF(arr[j+1][0], arr[j+1][1], arr[j+1][2]))
            {
                swap(arr, j, j+1);
            }
        }
    }
}

void printArray(float arr[][3], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%.2f, %.2f, %.2f) ", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("\n");
}

int main()
{
    float array[][3] = {{2, 1, 3}, {1, 2, 3}, {3, 1, 2}};
    int n = sizeof(array) / sizeof(array[0]);

    // Sắp xếp mảng
    bubbleSort(array, n);

    // In ra mảng sau khi sắp xếp
    printArray(array, n);
    return 0;
}