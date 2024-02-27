#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_chunk(char *chunk, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", chunk[i]);
    }
    printf("\n");
}

int main() {
    // Allocate memory
    char *chunk1 = (char*)malloc(sizeof(char) * 10);
    char *chunk2 = (char*)malloc(sizeof(char) * 10);

    if (chunk1 == NULL || chunk2 == NULL) {
        printf("Error! unable to allocate memory.\n");
        return -1;
    }

    // Fill chunk1 with some data
    for (int i = 0; i < 10; i++) {
        chunk1[i] = 'A'+ i;
    }

    // Copy content from chunk1 to chunk2 
    memcpy(chunk2, chunk1, 10);

    // Print chunk2
    printf("Chunk2 after copy: ");
    print_chunk(chunk2, 10);

    // Free chunk1
    free(chunk1);
    chunk1 = NULL;

    // Print chunk2 after freeing chunk1 
    printf("Chunk2 after freeing Chunk1: ");
    print_chunk(chunk2, 10);

    // Free chunk2 
    free(chunk2);
    chunk2 = NULL;

    return 0;
}