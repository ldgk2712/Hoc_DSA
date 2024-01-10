#include <stdio.h>

int binarySearch(int a[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int middle = left +  (right - left) / 2;

    if (a[middle] == key)
    {
        return middle;
    } 

    if (a[middle] > key)
    {
        return binarySearch(a, key, left, middle -1);
    }

    return binarySearch(a, key, middle+1, right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &key);

    // Gọi hàm tìm kiếm đệ quy
    int result = binarySearch(arr, key, 0, size-1);

    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d.\n", key, result);
    } else {
        printf("Phan tu %d khong duoc tim thay trong mang.\n", key);
    }

    return 0;
}