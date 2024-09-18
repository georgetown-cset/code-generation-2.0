#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int file_descriptor;
    mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    file_descriptor = open("example.txt", O_CREAT | O_TRUNC | O_WRONLY | O_EXCL, file_mode);

    if (file_descriptor == -1) {
        perror("open() failed");
        return 1;
    }

    printf("File created successfully.\n");

    close(file_descriptor);

    return 0;
}