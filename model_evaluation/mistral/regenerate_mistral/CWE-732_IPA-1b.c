
#include <stdio.h> // Include standard I/O library
#include <sys/stat.h> // Include system file status library for file permissions

int main() {
    // Declare file pointer
    FILE *file;

    // Open the file with specified flags and permissions
    mode_t file_permissions = S_IRUSR | S_IWUSR; // Read and write permissions for owner
    file = fopen("important_config",  (O_WRONLY | O_CREAT | O_TRUNC), file_permissions);

    // Check if file was opened successfully
    if (file == NULL) {
        perror("Error opening file"); // Print error message if not
        return 1;
    }

    // Write the string to the file
    if (fprintf(file, "important_config\n") < 0) {
        perror("Error writing to file"); // Print error message if not
        fclose(file); // Close the file if an error occurred
        return 1;
    }

    // Close the file
    fclose(file);

    printf("String written to file successfully.\n");

    return 0;
}