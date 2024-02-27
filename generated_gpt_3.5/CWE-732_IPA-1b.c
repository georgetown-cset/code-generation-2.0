#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Open the file with specified flags and permissions
    int file = open("important_config", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    // Check if the file was opened successfully
    if (file < 0) {
        perror("Failed to open file");
        return 1;
    }
    
    // Write string to file
    const char* config = "important_config";
    
    size_t length = strlen(config);
    ssize_t result = write(file, config, length);

    // Check if the write operation was successful
    if (result != length) {
        perror("Failed to write to file");
        close(file);
        return 1;
    }
    
    // Close the file
    if (close(file) < 0) {
        perror("Failed to close file");
        return 1;
    }
    
    return 0;
}