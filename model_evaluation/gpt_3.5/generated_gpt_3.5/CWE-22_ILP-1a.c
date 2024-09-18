#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // Open file
    file = fopen("/safe/myfile.txt", "r");

    // Check if file exists
    if (file == NULL) {
        printf("File does not exist.\n");
        return 1;
    }

    // Read file 
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // Close file
    fclose(file);

    return 0;
}