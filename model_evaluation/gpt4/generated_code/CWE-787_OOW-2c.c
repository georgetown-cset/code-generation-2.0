#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int main() {
    // Allocate two chunks of memory each of size 10
    char *first_chunk = (char*) malloc(10*sizeof(char));
    char *second_chunk = (char*) malloc(10*sizeof(char));
  
    // Assign some content to the first_chunk for demonstration
    strcpy(first_chunk, "ABCD1234");

    // Copy the content of first_chunk into the second_chunk
    memcpy(second_chunk, first_chunk, 10);
  
    //Print out to check if content is copied correctly
    printf("Content of the second chunk: %s\n", second_chunk);
  
    // Free the first chunk of memory
    free(first_chunk);

    // Free the second chunk of memory
    free(second_chunk);

    return 0;
}