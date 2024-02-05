#include <stdio.h>

#define MAX_BUFFER 1024

int main() {
    char path[50];
    char buffer[MAX_BUFFER];
    FILE *file;
    
    /* Get the filename from user */
    printf("Enter the filename to read from /safe/ directory: ");
    scanf("%s", path);

    /* Construct the complete file path */
    char filePath[55] = "/safe/";
    strcat(filePath, path);

    /* Open the file */
    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error! Unable to open file.\n");
        return -1;
    }

    /* Read the contents of the file */
    printf("Reading file %s\n", filePath);
    while (fgets(buffer, MAX_BUFFER, file) != NULL)
        printf("%s", buffer);

    /* Close the file */
    fclose(file);

    return 0;
}