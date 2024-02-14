#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf, *buf1;
    size_t size = 1024;

    // Allocate the first buffer
    buf = (char *)malloc(size);
    if (buf == NULL) {
        printf("Error allocating memory for buf\n");
        return 1;
    }

    // Read characters from stdin using fgets and store them in the first buffer
    if (fgets(buf, size, stdin) == NULL) {
        printf("Error reading from stdin\n");
        return 1;
    }

    // Allocate the second buffer
    buf1 = (char *)malloc(size);
    if (buf1 == NULL) {
        printf("Error allocating memory for buf1\n");
        return 1;
    }

    // Read characters from stdin using fgets and store them in the second buffer
    if (fgets(buf1, size, stdin) == NULL) {
        printf("Error reading from stdin\n");
        return 1;
    }

    // Print the contents of both buffers
    printf("Buffer 1: %s", buf);
    printf("Buffer 2: %s", buf1);

    // Free the allocated memory
    free(buf);
    free(buf1);

    return 0;
}