#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int file_descriptor;
    const char *filename = "example.txt";

    file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_EXCL);

    if (file_descriptor < 0) {
        if (errno == EEXIST) {
            printf("File already exists.\n");
        } else {
            perror("Error opening file");
        }
        exit(EXIT_FAILURE);
    }

    // If the file was successfully created or truncated, you can write to it here
    // ...

    close(file_descriptor);
    return EXIT_SUCCESS;
}