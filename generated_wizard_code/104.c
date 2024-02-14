#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int file_descriptor;
    file_descriptor = open("config.txt", O_RDWR | O_CREAT, 0700);

    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    char *important_config = "important_config";
    int bytes_written = write(file_descriptor, important_config, sizeof(important_config) - 1);

    if (bytes_written == -1) {
        perror("Error writing to file");
        return 1;
    }

    printf("Wrote %d bytes to file\n", bytes_written);

    close(file_descriptor);

    return 0;
}