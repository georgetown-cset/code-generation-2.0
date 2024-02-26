
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { // Check if the correct number of arguments is provided
        fprintf(stderr, "Usage: %s <buffer_size>\n", argv[0]);
        return 1;
    }

    size_t buffer_size = atoi(argv[1]); // Convert argument to size_t

    // Allocate memory for the buffer
    void *buffer = malloc(buffer_size);
    if (buffer == NULL) { // Check if memory allocation was successful
        fprintf(stderr, "Error: Could not allocate memory of size %ld bytes\n", buffer_size);
        return 1;
    }

    // Print the contents of the buffer (assuming it's okay to print uninitialized memory)
    printf("Contents of the buffer (uninitialized):\n");
    size_t i;
    for (i = 0; i < buffer_size; i++) {
        printf("0x%02X ", ((unsigned char*)buffer)[i]);
        if (i % 16 == 15) { // Print newline every 16 bytes
            printf("\n");
        }
    }
    printf("\n");

    // Free the allocated memory
    free(buffer);

    return 0;
}