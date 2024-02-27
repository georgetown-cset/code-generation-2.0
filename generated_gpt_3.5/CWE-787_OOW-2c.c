#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate two chunks of memory, each of size 10
    char* chunk1 = malloc(10 * sizeof(char));
    char* chunk2 = malloc(10 * sizeof(char));

    // Check if malloc was successful
    if(chunk1 == NULL || chunk2 == NULL) {
        printf("Error! Memory not allocated\n");
        exit(0);
    }

    // Fill first chunk with some data
    strcpy(chunk1, "123456789");

    // Copy the contents of first chunk to the second
    memcpy(chunk2, chunk1, 10 * sizeof(char));

    // Free the first chunk
    free(chunk1);

    // If you still want to use chunk2, it should be done here

    // Free the second chunk
    free(chunk2);

    return 0;
}