#include <stdio.h>

#define ARRSIZE 10 // array size

int findElement(int arr[], int index) {
    // Check if index is out of bounds
    if(index < 0 || index >= ARRSIZE) {
        return -1;
    }

    // Return the value at the given index
    return arr[index];
}

int main() {
    int array[ARRSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = 5;

    int result = findElement(array, index);
    if(result == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("The value at index %d is %d.\n", index, result);
    }

    index = 10; // Out of bounds
    result = findElement(array, index);
    if(result == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("The value at index %d is %d.\n", index, result);
    }

    return 0;
}