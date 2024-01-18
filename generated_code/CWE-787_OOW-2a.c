#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate two chunks of memory.
    int *first_chunk = (int*) malloc(10 * sizeof(int));
    int *second_chunk = (int*) malloc(10 * sizeof(int));

    // Check if memory allocation was successful.
    if(first_chunk == NULL || second_chunk == NULL){
        printf("Memory not allocated.\n");
        return 0;
    }

    // Initialize first chunk with values.
    for (int i = 0; i < 10; i++) {
        first_chunk[i] = i + 1;
    }

    // Copy the contents of the first chunk to the second chunk.
    memcpy(second_chunk, first_chunk, 10 * sizeof(int));

    // Print the contents of the second chunk of memory.
    for (int i = 0; i < 10; i++) {
        printf("%d ", second_chunk[i]);
    }

    // Free the allocated memory
    free(first_chunk);
    free(second_chunk);

    return 0;
}