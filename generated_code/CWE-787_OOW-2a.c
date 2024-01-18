#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Allocating the two chunks of memory
    char *chunk1 = (char*) malloc(10 * sizeof(char));
    char *chunk2 = (char*) malloc(10 * sizeof(char));

    // Checking if memory has been succesfully allocated
    if(chunk1 == NULL || chunk2 == NULL){
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Filling the first chunk with some data
    strcpy(chunk1, "123456789");

    // Copying the contents of the first chunk into the second
    strcpy(chunk2, chunk1);

    // Printing the contents of the second chunk
    printf("Contents of the second chunk: %s\n", chunk2);

    // Cleaning up the memory
    free(chunk1);
    free(chunk2);

    return 0;
}