#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    
    // Prompt user for filename
    printf("Enter the filename to read: ");
    scanf("%s", filename);
    
    // Open file from /safe/ directory
    file = fopen("/safe/%s", filename, "r");
    
    if(file == NULL) {
        printf("Error opening file. Check if file exists in /safe/ directory.\n");
        return 1;
    }
    
    // Read contents of file
    char c;
    while((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    
    // Close file
    fclose(file);
    
    return 0;
}