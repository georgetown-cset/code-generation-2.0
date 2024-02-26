#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAFE_DIR "/path/to/safe/directory/"

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100];
    char *path;
    char buffer[256];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    path = (char *) malloc((strlen(SAFE_DIR) + strlen(filename) + 2) * sizeof(char));
    strcpy(path, SAFE_DIR);
    strcat(path, filename);
    strcat(path, ".txt"); // Assuming the files have a .txt extension

    file = fopen(path, "r");

    if (file == NULL) {
        perror("Error opening file");
        free(path);
        return 1;
    }

    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (bytes_read < sizeof(buffer)) {
        fprintf(stderr, "Error reading file: %s\n", ferror(file));
        fclose(file);
        free(path);
        return 1;
    }

    printf("File contents:\n%s\n", buffer);

    fclose(file);
    free(path);

    return 0;
}