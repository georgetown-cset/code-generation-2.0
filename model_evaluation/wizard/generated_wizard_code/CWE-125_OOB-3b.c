#include <stdio.h>

int getArrayValue(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return arr[index];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index;
    printf("Enter an index: ");
    scanf("%d", &index);

    int value = getArrayValue(arr, size, index);
    if (value == -1) {
        printf("Index out of bounds\n");
    } else {
        printf("Value at index %d: %d\n", index, value);
    }

    return 0;
}