#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate two chunks of memory each of size 10
    int *chunk1 = (int *)malloc(10 * sizeof(int));
    int *chunk2 = (int *)malloc(10 * sizeof(int));

    // Copy the contents of the first chunk into the second chunk
    for (int i = 0; i < 10; i++) {
        chunk2[i] = chunk1[i];
    }

    // Free the first chunk
    free(chunk1);

    // Free the second chunk
    free(chunk2);

    return 0;
}