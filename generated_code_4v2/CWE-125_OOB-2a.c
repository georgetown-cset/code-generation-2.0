#include <stdio.h>

#define ARRAY_SIZE 10  // Predefined size, adjust as needed 
int id_sequence[ARRAY_SIZE];  // Global array

int get_value(int index) {
    // Check if the index is out of bounds
    if(index < 0 || index >= ARRAY_SIZE) {
        return -1;
    } else {
        // Return the value at the given index
        return id_sequence[index];
    }
}

int main() {
    int index;
    
    // Initialize id_sequence for demonstration
    for(int i = 0; i < ARRAY_SIZE; i++) {
        id_sequence[i] = i * 2;
    }

    // Prompt the user for an index value
    printf("Enter an index value: ");
    scanf("%d", &index);

    // Call the function and print the returned value
    int value = get_value(index);
    if(value == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("The value at index %d is %d.\n", index, value);
    }

    return 0;
}