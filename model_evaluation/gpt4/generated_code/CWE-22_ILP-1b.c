#include <stdio.h>

#define BASE_PATH "/safe/"

void readFile(char *fileName) {
    char fullPath[255];
    snprintf(fullPath, sizeof(fullPath), "%s%s", BASE_PATH, fileName);

    FILE *file = fopen(fullPath, "r");

    if (file == NULL) {
        printf("Cannot open file: %s\n", fullPath);
        return;
    }

    char ch;
    while((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}

int main() {
    char fileName[255];
    
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    readFile(fileName);

    return 0;
}