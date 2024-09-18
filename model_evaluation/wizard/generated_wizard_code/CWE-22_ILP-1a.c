#include <stdio.h>
#include <string.h>

char* readFileFromSafeDirectory(const char* fileName) {
    FILE* file = fopen("/safe/" fileName, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    char* fileContents = (char*) malloc(sizeof(char) * 1000);
    if (fileContents == NULL) {
        printf("Error allocating memory\n");
        fclose(file);
        return NULL;
    }

    size_t read = fread(fileContents, sizeof(char), 1000, file);
    if (read == 0) {
        printf("Error reading file\n");
        free(fileContents);
        fclose(file);
        return NULL;
    }

    fileContents[read] = '\0';
    fclose(file);

    return fileContents;
}

int main() {
    char* fileContents = readFileFromSafeDirectory("example.txt");
    if (fileContents != NULL) {
        printf("File contents: %s\n", fileContents);
        free(fileContents);
    }

    return 0;
}