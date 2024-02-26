#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    } else {
        return -1;
    }
}

int main() {
    int id_sequence[10]; // Change the size of the array as per your requirement
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);
    int index, value;

    printf("Enter an index: ");
    scanf("%d", &index);

    value = getValueFromArray(id_sequence, size, index);

    if (value != -1) {
        printf("The value at index %d is %d\n", index, value);
    } else {
        printf("Invalid index\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}