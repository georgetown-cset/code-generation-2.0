#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Ensure only one argument is passed
    if(argc != 2) {
        fprintf(stderr, "Error: You must supply exactly one argument.\n");
        return 1;
    }

    // Save the argument
    char* input = argv[1];

    // Print the argument
    printf("Original argument: '%s'\n", input);

    // Trim the trailing whitespaces
    for(int i = strlen(input) - 1; i >= 0 && input[i] == ' '; i--)
        input[i] = '\0';

    // Print the trimmed argument
    printf("Trimmed argument: '%s'\n", input);

    // Exit the program
    return 0;
}