#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for the first chunk
    int *chunk1 = (int *)malloc(10 * sizeof(int));

    // Allocate memory for the second chunk
    int *chunk2 = (int *)malloc(10 * sizeof(int));

    // Copy the contents of the first chunk into the second chunk
    for (int i = 0; i < 10; i++) {
        chunk2[i] = chunk1[i];
    }

    // Print the contents of the second chunk
    printf("Contents of the second chunk: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");

    // Free the memory allocated to the first chunk
    free(chunk1);

    // Print the contents of the second chunk again (should be the same as before)
    printf("Contents of the second chunk after freeing the first chunk: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", chunk2[i]);
    }
    printf("\n");

    // Free the memory allocated to the second chunk
    free(chunk2);

    return 0;
}