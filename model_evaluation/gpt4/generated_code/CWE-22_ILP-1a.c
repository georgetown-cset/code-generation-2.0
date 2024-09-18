#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // Open target file in the /safe/ directory
    file = fopen("/safe/target.txt", "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Cannot open file \n");
        return 0;
    }

    // Read the contents of the file
    ch = fgetc(file);
    while (ch != EOF) {
        printf ("%c", ch);
        ch = fgetc(file);
    }

    fclose(file);
    return 0;
}