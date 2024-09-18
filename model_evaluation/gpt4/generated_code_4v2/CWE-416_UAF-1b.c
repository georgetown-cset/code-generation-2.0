#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a buffer size as an argument.\n");
        return 1;
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        printf("Invalid buffer size. Please provide a positive integer.\n");
        return 1;
    }

    // Allocate the buffer
    char *buffer = (char*)malloc(size * sizeof(char));

    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize and print the buffer
    for (int i = 0; i < size; ++i) {
        buffer[i] = i % 256; // Initialization with some values.
        printf("%d ", buffer[i]);
    }

    // Free the buffer
    free(buffer);

    return 0;
}