#include <stdio.h>
#include <string.h>

// Function to remove trailing white space
void trimWhiteSpace(char* str) {
    int index, i;

    // Trim trailing white space
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            break;
        }
    }

    return;
}

// Main Function
int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("No arguments provided. Please provide at least one argument.\n");
        return -1;
    }
  
    // Trim white-space and print command line arguments
    for (int i = 1; i < argc; i++) {
        trimWhiteSpace(argv[i]);
        printf("Trimmed argument[%d]: %s\n", i, argv[i]);
    }

    return 0;
}