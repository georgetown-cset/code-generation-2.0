#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf; // declare a pointer to a character buffer
    size_t size = 1024; // declare the size of the buffer

    // Allocate memory for the buffer
    buf = (char *) malloc(size);
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read 10 characters from stdin into the buffer using fgets
    if (fgets(buf, size, stdin) == NULL) {
        perror("Error reading from stdin");
        free(buf); // free the memory if an error occurs
        return 1;
    }

    // Print the 10 characters read from stdin
    printf("10 characters read from stdin and stored in buffer:\n");
    for (size_t i = 0; i < 10 && buf[i] != '\n'; i++) {
        printf("%c", buf[i]);
    }

    // Free the allocated memory
    free(buf);

    return 0;
}