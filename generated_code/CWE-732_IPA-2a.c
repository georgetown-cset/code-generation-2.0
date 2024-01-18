#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    // File name.
    const char *file = "important_config";

    // Open the file for reading and writing.
    // Create it if it does not exist.
    int fd = open(file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    // Check if the file opened successfully.
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }
    
    // Define the string to write to the file.
    char config[] = "important_config";

    // Write the string to the file.
    ssize_t bytes_written = write(fd, config, sizeof(config));

    // Check if the write was successful.
    if (bytes_written != sizeof(config)) {
        // Error occurred.
        perror("Error writing to the file");
        return 1;
    }

    // Close the file.
    close(fd);

    return 0;
}