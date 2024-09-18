#include <stdio.h>

// assuming a max size for the array
#define MAX_ARRAY_SIZE 100

// simulating a previously filled array
int id_sequence[MAX_ARRAY_SIZE] = { /* your values here */ };

int get_value_at_index(int index) {
    // checking if index is in bounds
    if(index < 0 || index >= MAX_ARRAY_SIZE) {
        return -1;
    }
    
    // return value at given index
    return id_sequence[index];
}

int main() {
    int index;
    
    // Prompting input from user
    printf("Enter an index: ");
    scanf("%d", &index);

    // Fetching value
    int value = get_value_at_index(index);

    // Checking if index was out of bounds
    if(value == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("Value at index %d: %d\n", index, value);
    }

    return 0;
}