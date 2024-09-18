
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int file_fd;
    mode_t file_permissions = S_IRUSR | S_IWUSR; // read and write permissions for owner

    if ((file_fd = open("important_config", O_CREAT | O_TRUNC | O_WRONLY, file_permissions)) < 0) {
        perror("Error creating file important_config");
        return 1;
    }

    // Write to the file or perform other operations here

    close(file_fd);
    return 0;
}