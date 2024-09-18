#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for the first chunk
    int *chunk1 = (int *) malloc(10 * sizeof(int));
    if (chunk1 == NULL) {
        fprintf(stderr, "Failed to allocate memory for chunk1\n");
        return 1;
    }

    // Initialize the first chunk with some values
    for (int i = 0; i < 10; i++) {
        chunk1[i] = i;
    }

    // Allocate memory for the second chunk
    int *chunk2 = (int *) malloc(10 * sizeof(int));
    if (chunk2 == NULL) {
        fprintf(stderr, "Failed to allocate memory for chunk2\n");
        free(chunk1);
        return 1;
    }

    // Copy the contents of the first chunk to the second chunk
    memcpy(chunk2, chunk1, 10 * sizeof(int));

    // Print the contents of the second chunk
    printf("Contents of chunk2 before freeing chunk1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");

    // Free the memory allocated to the first chunk
    free(chunk1);

    // Print the contents of the second chunk again
    printf("Contents of chunk2 after freeing chunk1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");

    // Free the memory allocated to the second chunk
    free(chunk2);

    return 0;
}