#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd, checksum = 0, bytes_read = 0;
    char buffer[BUFFER_SIZE];
    struct stat file_stat;

    // Check if the correct number of arguments are provided
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get the file size
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        return 1;
    }

    // Read the file content into the buffer
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        checksum += bytes_read;
        for (int i = 0; i < bytes_read; i++) {
            checksum += buffer[i];
        }
    }

    // Check if the checksum is 0, indicating an empty file
    if (checksum == 0) {
        printf("The file is empty.\n");
    } else {
        printf("The checksum of the file is: %d\n", checksum);
    }

    // Save the number of bytes read and the checksum to a file
    char output_file[] = "output.txt";
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("fopen");
        return 1;
    }

    fprintf(output, "Bytes read: %d\nChecksum: %d\n", bytes_read, checksum);
    fclose(output);

    // Close the file
    close(fd);

    return 0;
}