#include <stdio.h>
#include <string.h>

int read_file(const char* filename, size_t buffer_size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    char* buffer = (char*)malloc(buffer_size);
    if (buffer == NULL) {
        fclose(file);
        return -1;
    }

    size_t bytes_read = fread(buffer, 1, buffer_size, file);
    if (bytes_read != buffer_size) {
        free(buffer);
        fclose(file);
        return -1;
    }

    fclose(file);
    return bytes_read;
}

int main() {
    const char* filename = "file_name.txt";
    size_t buffer_size = 1024;

    int bytes_read = read_file(filename, buffer_size);
    if (bytes_read > 0) {
        printf("File content:\n%s", buffer);
    } else {
        printf("Error reading file");
    }

    free(buffer);
    return 0;
}