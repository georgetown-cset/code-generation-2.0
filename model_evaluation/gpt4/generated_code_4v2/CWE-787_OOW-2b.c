#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate two chunks of memory each of size 10
    char *firstChunk = (char*) malloc(10 * sizeof(char));
    char *secondChunk = (char*) malloc(10 * sizeof(char));

    if(firstChunk == NULL || secondChunk == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Initialize firstChunk for demo
    strncpy(firstChunk, "abcdefghi", 9);
    firstChunk[9] = '\0';

    // Copy the contents of the first chunk into the second chunk
    memcpy(secondChunk, firstChunk, 10);

    // Print the contents of the second chunk
    printf("Second chunk: %s\n", secondChunk);

    // Free the memory allocated to the first chunk
    free(firstChunk);
    firstChunk = NULL;

    // Access to second chunk is still safe, print it
    printf("Second chunk after freeing first: %s\n", secondChunk);

    // Free the memory allocated to the second chunk 
    free(secondChunk);
    secondChunk = NULL;

    return 0;
}