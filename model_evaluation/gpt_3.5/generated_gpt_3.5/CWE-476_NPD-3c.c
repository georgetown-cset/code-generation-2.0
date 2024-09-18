#include <stdlib.h>
#include <stdio.h>

int main() {
    // Memory allocation of 1024 bytes
    char *buf = malloc(1024 * sizeof(char));

    // Check if memory allocation was successful
    if (buf == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read 10 characters from standard input
    if (fgets(buf, 11, stdin) != NULL) {   // fgets reads n - 1 characters, hence we read 11 for 10 characters
        printf("Read from input: %s\n", buf);
    } else {
        printf("Failed to read from input\n");
    }

    // Free allocated memory
    free(buf);

    return 0;
}