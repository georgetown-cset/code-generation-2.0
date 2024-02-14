#include <stdio.h>
#include <string.h>

int read_file(const char* filename, char* buffer, size_t* length) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 1;
    }

    size_t read_length = fread(buffer, 1, sizeof(char), file);
    if (read_length == 0) {
        return 2;
    }

    *length = ftell(file);
    fclose(file);
    return 0;
}

int main() {
    const char* requested_file = "safe_directory/requested_file.txt";
    char buffer[1024];
    size_t file_length;

    int result = read_file(requested_file, buffer, &file_length);
    if (result == 0) {
        printf("File content:\n%s", buffer);
    } else {
        printf("Error reading file: %d", result);
    }

    return 0;
}