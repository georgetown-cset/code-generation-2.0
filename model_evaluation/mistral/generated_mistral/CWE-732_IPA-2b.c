#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int file_descriptor;
    const mode_t permissions = S_IRUSR | S_IWUSR | S_RDGRP | S_WRGRP | S_IXUSR | S_IXGRP | S_IXOTH;

    if ((file_descriptor = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY | O_EXCL, permissions)) < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // At this point, the file has been created or truncated, and we have a file descriptor for it.
    // You can now write to the file using standard I/O functions like write() or fprintf().

    // Don't forget to close the file when you're done!
    close(file_descriptor);

    return EXIT_SUCCESS;
}