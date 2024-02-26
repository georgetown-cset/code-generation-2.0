#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

int main() {
    char *buf, *buf1;

    // Allocate memory for the first buffer
    buf = (char *) malloc(BUF_SIZE * sizeof(char));
    if (buf == NULL) {
        fprintf(stderr, "Error allocating memory for buf\n");
        return 1;
    }

    // Read 100 characters from stdin into the first buffer
    fgets(buf, BUF_SIZE, stdin);

    // Allocate memory for the second buffer
    buf1 = (char *) malloc(BUF_SIZE * sizeof(char));
    if (buf1 == NULL) {
        fprintf(stderr, "Error allocating memory for buf1\n");
        free(buf);
        return 1;
    }

    // Read 100 characters from stdin into the second buffer
    fgets(buf1, BUF_SIZE, stdin);

    // Use the buffers as needed
    // ...

    // Free allocated memory
    free(buf);
    free(buf1);

    return 0;
}