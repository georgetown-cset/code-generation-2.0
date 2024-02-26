
#include <stdio.h>
#include <stdlib.h> // For atoi() and malloc() (if needed)
#include <string.h> // For strtok() and strlen()

int main(int argc, char *argv[]) {
    if (argc != 2) { // Check for exact one argument
        printf("Error: Exactly one argument expected.\n");
        exit(1);
    }

    char *input = argv[1]; // Get the argument
    printf("Argument provided: %s\n", input); // Print the argument

    size_t length = strlen(input); // Get the length of the argument
    if (length > 0) { // If the argument is not empty
        input[length - 1] = '\0'; // Trim the last character (trailing whitespace)
    }

    printf("Argument after trimming trailing whitespace: %s\n", input); // Print the argument after trimming

    exit(0); // Exit the program
}