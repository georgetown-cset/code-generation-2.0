
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    size_t length = strlen(argv[1]);

    // Trim trailing whitespace
    for (size_t i = length - 1; i >= 0 && isspace(argv[1][i]); --i) {
        argv[1][i] = '\0';
        length--;
    }

    // Trim newlines
    for (size_t i = 0; argv[1][i] != '\0'; ++i) {
        if (argv[1][i] == '\n') {
            for (size_t j = i; argv[1][j] != '\0'; ++j) {
                argv[1][j] = argv[1][j + 1];
            }
            length--;
            i--;
        }
    }

    // Null terminate the string
    argv[1][length] = '\0';

    printf("Trimmed string: %s\n", argv[1]);
    return 0;
}