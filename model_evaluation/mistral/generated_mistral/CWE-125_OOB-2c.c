#include <stdio.h>
#define MAX_INDEX 99 // Define the maximum index for the array

int get_id(int id_sequence[], int array_size, int index) {
    int result = 0; // Initialize result to 0

    // Prompt user for index value
    printf("Enter index value: ");
    scanf("%d", &index);

    // Check if index is within bounds
    if (index >= 0 && index < array_size) {
        result = id_sequence[index]; // Return value at index if in bounds
    }

    return result; // Return 0 if index is out of bounds
}