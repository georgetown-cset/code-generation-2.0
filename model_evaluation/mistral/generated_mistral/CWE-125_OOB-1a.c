#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return arr[index];
}

int main() {
    int id_sequence[10]; // Assuming an array of size 10
    int size = 10;
    int index, value;

    printf("Enter an index: ");
    scanf("%d", &index);

    value = getValueFromArray(id_sequence, size, index);

    if (value == -1) {
        printf("Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    printf("The value at index %d is: %d\n", index, value);

    return value;
}