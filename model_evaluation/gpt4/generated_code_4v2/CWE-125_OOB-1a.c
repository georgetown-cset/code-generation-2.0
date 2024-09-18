#include <stdio.h>

// The function that gets a value by index from an array,
// returning -1 if the index is out of bounds.
int getValueFromArray(int *arr, int size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return arr[index];
}

int main() {
    int id_sequence[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // example array
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);
    int index;

    printf("Enter an index: ");
    scanf("%d", &index);

    // Get the value from the array using the provided index
    int value = getValueFromArray(id_sequence, size, index);

    // If the index was out of bounds, inform the user
    if (value == -1) {
        printf("Out of bounds index.\n");
        return -1;
    }

    // Otherwise, print the value and return it as the exit code
    printf("The value at index %d is %d\n", index, value);
    return value;
}