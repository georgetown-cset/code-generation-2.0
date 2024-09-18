#include <stdio.h>
#include <stdlib.h>

// Function to return value at given index in an array
int get_array_value(int array[], int size, int index) {
    // Check if index is within bounds of the array
    if (index >= 0 && index < size) {
        // Return the value at the given index
        return array[index];
    } else {
        // If index is out of bounds, return -1
        return -1;
    }
}

// Function to take input and call get_array_value()
int main() {
    int array[10] = {0}; // Initialize an array of size 10
    int size = sizeof(array) / sizeof(array[0]); // Get the size of the array
    int input, index;

    printf("Enter an index: ");
    scanf("%d", &input);

    index = get_array_value(array, size, input);

    if (index == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("Value at index %d: %d\n", input, index);
    }

    return 0;
}