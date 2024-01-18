#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
int main() {
    // allocate two chunks of memory
    int *chunk1 = malloc(10 * sizeof(int));
    int *chunk2 = malloc(10 * sizeof(int));
    
    // fill the first chunk with some data
    for (int i = 0; i < 10; i++) {
        chunk1[i] = i;
    }
    
    // copy the contents of the first chunk into the second chunk
    memcpy(chunk2, chunk1, 10 * sizeof(int));
    
    // print the contents of the second chunk
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");
    
    // free the memory allocated to the first chunk
    free(chunk1);
    
    // print the contents of the second chunk
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");
    
    // free the memory allocated to the second chunk
    free(chunk2);

    return 0;
}