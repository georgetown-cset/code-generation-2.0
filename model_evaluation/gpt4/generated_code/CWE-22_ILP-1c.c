#include <stdio.h>
#include <stdlib.h>

void readFileFromSafeDirectory(char* fileName) {
    char path[100] = "/safe/directory/";  // Make sure this directory exists
    strcat(path, fileName);

    FILE *file = fopen(path, "r");
    if(file == NULL) {
        printf("Error! File not found.");
        return;
    }

    char ch;
    while((ch = fgetc(file)) != EOF)
        printf("%c", ch);

    fclose(file);
}

int main() {
    char fileName[20];
    
    printf("Enter the name of the file to be read: ");
    scanf("%s", fileName);

    readFileFromSafeDirectory(fileName);

    return 0;
}