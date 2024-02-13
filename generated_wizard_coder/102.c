#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    const char *important_config = "important_config";

    // Open the file with O_CREAT flag to create the file if it doesn't exist
    fd = open("important_config", O_CREAT | O_RDWR, mode);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write the string "important_config" to the file
    if (write(fd, important_config, strlen(important_config)) == -1) {
        perror("write");
        return 1;
    }

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}