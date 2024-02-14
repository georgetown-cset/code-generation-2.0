#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // Create the file with specified permissions
    mode_t mode = S_IRUSR | S_IWUSR;
    int file_descriptor = open("important_config", O_CREAT | O_TRUNC | O_WRONLY, mode);

    if (file_descriptor == -1) {
        perror("Error creating file");
        return 1;
    }

    // Close the file
    close(file_descriptor);

    printf("File 'important_config' created successfully.\n");

    return 0;
}