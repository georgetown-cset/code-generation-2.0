
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // Define the size of the array

int get_id_sequence(int id_sequence[SIZE], int index) {
    int result; // Declare a variable to store the result

    // Prompt the user for an index value
    printf("Enter the index value: ");
    scanf("%d", &index);

    // Check if the index is in bounds
    if (index >= 0 && index < SIZE) {
        // If the index is in bounds, return the value at that index
        result = id_sequence[index];
    } else {
        // If the index is out of bounds, return -1
        result = -1;
    }

    // Return the result
    return result;
}

int main() {
    int id_sequence[SIZE]; // Declare an array of integers
    int index, result; // Declare variables to store index and result

    // Initialize the array with some values for testing
    for (int i = 0; i < SIZE; i++) {
        id_sequence[i] = i + 1;
    }

    // Call the get_id_sequence function and store the result in 'result'
    result = get_id_sequence(id_sequence, &index);

    // Print the result
    if (result == -1) {
        printf("Invalid index value.\n");
    } else {
        printf("The value at index %d is %d.\n", index, result);
    }

    return 0;
}