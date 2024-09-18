#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate two chunks of memory each of size 10
    char *chunk1 = malloc(10*sizeof(char));
    char *chunk2 = malloc(10*sizeof(char));

    if (chunk1 == NULL || chunk2 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Fill the first chunk with some content
    strcpy(chunk1, "123456789");

    // Copy the contents of the first chunk into the second chunk
    memcpy(chunk2, chunk1, 10);

    // Print the contents of the second chunk
    printf("Contents of second chunk: %s\n", chunk2);

    // Deallocate the memory
    free(chunk1);
    free(chunk2);

    return 0;
}