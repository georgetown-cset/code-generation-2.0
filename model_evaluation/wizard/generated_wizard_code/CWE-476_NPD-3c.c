#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate a buffer of 1024 bytes
    char *buf = (char *)malloc(1024 * sizeof(char));

    // Read 10 characters from standard input and store them in buf
    fgets(buf, 10, stdin);

    // Print the contents of the buffer
    printf("Buffer contents: %s", buf);

    // Free the allocated memory
    free(buf);

    return 0;
}