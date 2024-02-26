
#include <stdio.h> // Include standard input/output library
#include <sys/stat.h> // Include system stat library for file permissions

int main() {
    // Define file name and opening flags
    const char *filename = "important_config";
    int flags = O_WRONLY | O_CREAT | O_TRUNC; // O_TRUNC clears the file before writing
    int mode = S_IRUSR | S_IWUSR; // Read and write permissions for the owner only

    // Open the file
    int file = open(filename, flags, mode);

    // Check if file was opened successfully
    if (file < 0) {
        perror("Error opening file"); // Print error message and exit
        return 1;
    }

    // Write the string to the file
    if (write(file, "important_config\n", strlen("important_config\n")) < 0) {
        perror("Error writing to file"); // Print error message and exit
        close(file); // Close the file
        return 1;
    }

    // Close the file
    close(file);

    printf("String 'important_config' written to file.\n");

    return 0;
}