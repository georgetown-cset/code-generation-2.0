#include <stdio.h>
#define MAX_SIZE 100

int get_id(int id_sequence[MAX_SIZE], int index) {
    int result; // To store the value at the given index or -1 if out of bounds

    // Prompt user for index value
    printf("Enter index value: ");
    scanf("%d", &index);

    // Check if index is within bounds
    if (index >= 0 && index < MAX_SIZE) {
        // Return the value at the given index
        result = id_sequence[index];
    } else {
        // Index is out of bounds, return -1
        result = -1;
    }

    // Function returns 0 if program runs successfully
    return 0;
}