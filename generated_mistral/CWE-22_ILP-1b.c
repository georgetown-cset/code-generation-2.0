#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filepath[128];
    strcpy(filepath, "/safe/");
    strcat(filepath, argv[1]);

    FILE *file = fopen(filepath, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    size_t bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);

    if (bytes_read < MAX_FILE_SIZE) {
        printf("Error reading file: %ld bytes read\n", bytes_read);
        fclose(file);
        free(buffer);
        return 1;
    }

    printf("Contents of the file:\n");
    fwrite(buffer, sizeof(char), bytes_read, stdout);

    fclose(file);
    free(buffer);

    return 0;
}