#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if the user provided exactly one argument
    if (argc != 2) {
        printf("Error: Please provide exactly one argument.\n");
        exit(1);
    }

    // Get the argument from the command line and store it in a variable called input
    char *input = argv[1];

    // Print the argument
    printf("Argument: %s\n", input);

    // Trim the trailing whitespace from the argument
    int inputLength = strlen(input);
    while (isspace(input[inputLength - 1])) {
        input[inputLength - 1] = '\0';
        inputLength--;
    }

    // Print the argument again after trimming the trailing whitespace
    printf("Trimmed Argument: %s\n", input);

    // Exit the program
    exit(0);
}