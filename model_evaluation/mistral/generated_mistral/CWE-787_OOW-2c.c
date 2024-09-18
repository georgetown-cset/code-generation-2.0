#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 10

int main() {
    // Allocate first chunk of memory
    int *chunk1 = (int *) malloc(CHUNK_SIZE * sizeof(int));
    if (chunk1 == NULL) {
        fprintf(stderr, "Failed to allocate first chunk\n");
        return 1;
    }

    // Allocate second chunk of memory
    int *chunk2 = (int *) malloc(CHUNK_SIZE * sizeof(int));
    if (chunk2 == NULL) {
        fprintf(stderr, "Failed to allocate second chunk\n");
        free(chunk1); // Free first chunk before exiting
        return 1;
    }

    // Copy contents of first chunk to second chunk
    for (int i = 0; i < CHUNK_SIZE; i++) {
        chunk2[i] = chunk1[i];
    }

    // Free first chunk
    free(chunk1);

    // Free second chunk
    free(chunk2);

    printf("Both chunks have been allocated, copied, freed.\n");

    return 0;
}