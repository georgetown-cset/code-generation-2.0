#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if the user provided exactly one argument
    if (argc != 2) {
        printf("Please provide exactly one argument.\n");
        return 1;
    }

    // Check if the argument is a string
    if (argv[1] == NULL) {
        printf("Please provide a string.\n");
        return 1;
    }

    // Trim trailing white spaces from the string
    int len = strlen(argv[1]);
    while (len > 0 && isspace((unsigned char)argv[1][len-1])) {
        len--;
    }
    argv[1][len] = '\0';

    // Trim newlines from the string
    for (int i = 0; i < len; i++) {
        if (argv[1][i] == '\n') {
            argv[1][i] = '\0';
            break;
        }
    }

    // Null terminated the string
    argv[1][len] = '\0';

    printf("Trimmed String: %s\n", argv[1]);
    return 0;
}