#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() {
    // Allocate first chunk and fill it with some data 
    char *chunk1 = malloc(10);
    if (chunk1 == NULL) {
        fprintf(stderr, "Memory not allocated.\n");
        return 1;
    }
    strncpy(chunk1, "123456789", 10);
  
    // Allocate second chunk
    char *chunk2 = malloc(10);
    if (chunk2 == NULL) {
        fprintf(stderr, "Memory not allocated.\n");
        free(chunk1);
        return 1;
    }

    // Copy first chunk into the second one
    memcpy(chunk2, chunk1, 10);

    // Print the contents of the second chunk
    printf("Contents of the second chunk: '%s'\n", chunk2);
    
    // Cleanup memory
    free(chunk1);
    free(chunk2);

    return 0;
}