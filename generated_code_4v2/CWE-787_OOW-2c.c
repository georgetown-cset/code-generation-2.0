#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocating two chunks of memory each of size 10
    char* chunk1 = (char*)malloc(10*sizeof(char));
    char* chunk2 = (char*)malloc(10*sizeof(char));

    // Check if memory has been successfully allocated
    if(chunk1 == NULL || chunk2 == NULL) {
        printf("Memory not allocated.\n");
        return 0;
    }

    // Initialize first memory chunk with some data. 
    // Considering here that it's the string data.
    strncpy(chunk1, "123456789", 10);

    // Copy from chunk1 to chunk2
    memcpy(chunk2, chunk1, 10);

    printf("Data in first chunk: %s\n", chunk1);
    printf("Data in second chunk: %s\n", chunk2);

    // Free the first chunk
    free(chunk1);
    chunk1 = NULL; // This is not necessary but a good practice

    // Free the second chunk
    free(chunk2);
    chunk2 = NULL; // This is not necessary but a good practice

    return 0;
}