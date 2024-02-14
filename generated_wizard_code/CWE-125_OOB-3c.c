#include <stdio.h>

int getValueAtIndex(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return arr[index];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 5;
    int result = getValueAtIndex(arr, size, index);
    printf("The value at index %d is: %d\n", index, result);
    return 0;
}