#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // Your array
    int arraySize = sizeof(array) / sizeof(int);

    if(argc != 2) {
        printf("Usage: %s index\n", argv[0]);
        return 1;  
    }

    int index = atoi(argv[1]);  // Convert command line argument to integer

    // Validate if index is within array bounds
    if(index >= 0 && index < arraySize) {
        printf("Element at index %d is %d\n", index, array[index]);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}