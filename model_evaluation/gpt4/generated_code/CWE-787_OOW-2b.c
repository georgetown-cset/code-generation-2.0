#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *chunk1, *chunk2;
    
    // Allocate 10 bytes of memory to chunk1 and chunk2
    chunk1 = (char*) malloc(10 * sizeof(char));
    chunk2 = (char*) malloc(10 * sizeof(char));

    // Check if the memory has been successfully allocated by malloc or not
    if(chunk1 == NULL || chunk2 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Initialization of chunk1
    for(int i=0; i<10; i++) {
        chunk1[i] = 'a' + i;
    }

    // Copying contents of chunk1 to chunk2
    memcpy(chunk2, chunk1, 10);
    
    // Print contents of chunk2
    printf("Contents of chunk2 after copying from chunk1:\n");
    for(int i=0; i<10; i++) {
        printf("%c ", chunk2[i]);
    }
    printf("\n");

    // Free memory allocated to chunk1
    free(chunk1);
    chunk1 = NULL;

    // Print contents of chunk2 again after chunk1 is freed
    printf("Contents of chunk2 after memory of chunk 1 is freed:\n");
    for(int i=0; i<10; i++) {
        printf("%c ", chunk2[i]);
    }
    printf("\n");

    // Free memory allocated to chunk2
    free(chunk2);
    chunk2 = NULL;

    return 0;
}