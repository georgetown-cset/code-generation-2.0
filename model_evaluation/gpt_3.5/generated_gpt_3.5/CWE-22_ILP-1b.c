#include <stdio.h>

void read_file(const char* filename) {
    // note input file path is limited to 256 Characters for demonstration purposes
    char filepath[256];
    
    // Ensure the requested file is in the '/safe/' directory
    snprintf(filepath, sizeof(filepath), "/safe/%s", filename);
    
    // Open the file in read mode.
    FILE *file = fopen(filepath, "r");
    if(file == NULL) {
        printf("Error opening file. Make sure the file path is correct.\n");
        return;
    }

    // Read and display the contents of the file.
    char ch;
    while((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // Finally close the file.
    fclose(file);
}

int main() {
    // arbitrary file name for demonstration purposes
    char* filename = "example.txt";
    read_file(filename);
    return 0;
}