#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd_in, fd_out;
    char buffer[BUFFER_SIZE];
    int bytes_read, checksum = 0;
    struct stat file_stat;

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open input file
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        return 1;
    }

    // Get file size
    if (fstat(fd_in, &file_stat) == -1) {
        perror("fstat");
        return 1;
    }

    // Open output file
    fd_out = open(argv[2], O_WRONLY | O_CREAT, file_stat.st_mode);
    if (fd_out == -1) {
        perror("open");
        return 1;
    }

    // Read file and calculate checksum
    while ((bytes_read = read(fd_in, buffer, BUFFER_SIZE)) > 0) {
        checksum += bytes_read;
        write(fd_out, &bytes_read, sizeof(int));
        write(fd_out, &checksum, sizeof(int));
    }

    // Write checksum if buffer is empty
    if (checksum == 0) {
        write(fd_out, &checksum, sizeof(int));
    }

    // Close files
    close(fd_in);
    close(fd_out);

    return 0;
}