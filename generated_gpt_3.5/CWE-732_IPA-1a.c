#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char* file_name = "important_config";
    int permissions = S_IRUSR | S_IWUSR;

    // Open with flags O_CREAT | O_TRUNC | O_WRONLY
    int file_descriptor = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, permissions);

    if(file_descriptor < 0) {
        perror("Error opening file");
        return -1;
    }

    // Close the file descriptor
    if(close(file_descriptor) < 0) {
        perror("Error closing file");
        return -1;
    }

    return 0;
}