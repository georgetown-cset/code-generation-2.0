#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int arr[], int size, int index);

int main() {
    int id_sequence[] = {1, 2, 3, 4, 5};
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);

    int input;
    printf("Enter an index: ");
    scanf("%d", &input);

    int result = getValueFromArray(id_sequence, size, input);
    if (result == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("Value at index %d: %d\n", input, result);
    }

    return result;
}

int getValueFromArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    } else {
        return arr[index];
    }
}