#include <stdio.h>

int linearSearch(int a[], int key, int index, int n)
{
    if (index == n)
    {
        return -1;
    }

    if (a[index] == key)
    {
        return index;
    }

    return linearSearch(a, key, index+1, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &key);

    // Gọi hàm tìm kiếm đệ quy
    int result = linearSearch(arr, key, 0, size);

    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d.\n", key, result);
    } else {
        printf("Phan tu %d khong duoc tim thay trong mang.\n", key);
    }

    return 0;
}