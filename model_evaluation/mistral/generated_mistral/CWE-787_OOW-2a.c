#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for the first chunk
    int *chunk1 = (int *) malloc(10 * sizeof(int));

    // Allocate memory for the second chunk
    int *chunk2 = (int *) malloc(10 * sizeof(int));

    // Check if memory was allocated successfully
    if (chunk1 == NULL || chunk2 == NULL) {
        printf("Error: Failed to allocate memory\n");
        free(chunk1);
        free(chunk2);
        return 1;
    }

    // Initialize the first chunk with some values
    for (int i = 0; i < 10; i++) {
        chunk1[i] = i * i;
    }

    // Copy the contents of the first chunk into the second one
    for (int i = 0; i < 10; i++) {
        chunk2[i] = chunk1[i];
    }

    // Print the contents of the second chunk
    printf("Contents of the second chunk:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(chunk1);
    free(chunk2);

    return 0;
}