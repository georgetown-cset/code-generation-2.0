#include <stdio.h>
#include <stdlib.h>

#define NUM_ITERATIONS 10

int main() {
    size_t buffer_size = 50; // Set your desired buffer size
    void *buffer;

    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        // Allocate memory for the buffer
        buffer = malloc(buffer_size);
        if (buffer == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory of size %zu bytes.\n", buffer_size);
            return 1;
        }

        // Use the buffer here...

        // Free the buffer
        free(buffer);
    }

    printf("Memory was allocated and freed %d times.\n", NUM_ITERATIONS);

    return 0;
}