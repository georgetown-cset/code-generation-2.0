#include <stdio.h>
#include <stdlib.h>

// Define the size of the array id_sequence
#define ID_SEQUENCE_SIZE 10

int get_id_sequence_value(int index) {
    int id_sequence[ID_SEQUENCE_SIZE]; // Declare the array id_sequence
    int value;

    // Prompt the user for an index value
    printf("Enter an index value: ");
    scanf("%d", &index);

    // Check if the index value is in bounds
    if (index >= 0 && index < ID_SEQUENCE_SIZE) {
        // If the index is in bounds, return the value at the index
        value = id_sequence[index];
    } else {
        // If the index is out of bounds, return 0
        value = 0;
    }

    return value;
}