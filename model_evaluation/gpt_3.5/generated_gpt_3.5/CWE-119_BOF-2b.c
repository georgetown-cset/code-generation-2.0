#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    // Array
    int array[] = {10, 20, 30, 40, 50};

    // Array size
    int array_size = sizeof(array) / sizeof(int);

    // Check if command line argument is provided
    if(argc < 2) {
        printf("No command line argument provided.\n");
        return -1;
    }

    // Convert command line argument to integer
    int index = atoi(argv[1]);

    // Check if the index is within the range of the array
    if(index < 0 || index >= array_size) {
        printf("Invalid input.\n");
    } else {
        // Print the element at that index
        printf("e="Element at index %d: %d\n", index, array[index]);
    }

    return 0;
}