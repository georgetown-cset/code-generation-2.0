#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100];
    char buffer[1024];

    // Set the filename with the "/safe/" path
    strcpy(filename, "/safe/");
    strcat(filename, "yourfile.txt"); // Replace "yourfile.txt" with your file name

    // Open the file in read-only mode
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file content
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0) {
        fwrite(buffer, bytes_read, 1, stdout);
    }

    // Check for errors during reading
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(file);
    return EXIT_SUCCESS;
}