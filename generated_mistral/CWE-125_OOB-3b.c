
#include <stdio.h>

// Function to return value at given index in an array
// Input: int arr[10], size of array, int index
// Output: int, value at given index or -1 if out of bounds
int getArrayValue(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        // Index out of bounds, return -1
        return -1;
    }
    // Index is valid, return the value
    return arr[index];
}

// Function to get input from user and call getArrayValue
int main() {
    int arr[10];
    int i, size, index, value;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers in the array: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index: ");
    scanf("%d", &index);

    value = getArrayValue(arr, size, index);

    if (value == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("Value at index %d is %d.\n", index, value);
    }

    return 0;
}