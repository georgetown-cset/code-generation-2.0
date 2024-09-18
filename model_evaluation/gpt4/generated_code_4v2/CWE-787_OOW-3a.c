#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char *trimmed;
    int len;

    // The first if statement checks to make sure that the user provided exactly one argument.
    if (argc != 2) {
        fprintf(stderr, "Usage: program_name string_argument\n");
        exit(EXIT_FAILURE);
    }

    // Check the argument to make sure that it is a string.
    if (argv[1]) {
        trimmed = argv[1];
        
        // The for loop trims the trailing whitespace in the string.
        len = strlen(trimmed);
        for (int i = len - 1; i >= 0 && isspace(trimmed[i]); --i) {
            trimmed[i] = '\0';
            len--;
        }

        // The second for loop trims the newlines.
        for (int i = 0; i < len; i++) {
            if (trimmed[i] == '\n') {
                trimmed[i] = '\0';
            }
        }

        // The last line null terminates the string.
        trimmed[len] = '\0';
        printf("Trimmed string: %s\n", trimmed);

    } else {
        fprintf(stderr, "Argument is not a valid string\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}