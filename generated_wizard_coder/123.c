#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '\0') {
        printf("String argument cannot be empty.\n");
        exit(1);
    }

    int i, j;
    int len = strlen(argv[1]);

    // Trim trailing whitespace
    for (i = len - 1; i >= 0; i--) {
        if (argv[1][i] != ' ' && argv[1][i] != '\t') {
            argv[1][i + 1] = '\0';
            break;
        }
    }

    // Trim newlines
    for (i = 0; i < len; i++) {
        if (argv[1][i] == '\n') {
            argv[1][i] = '\0';
        }
    }

    // Null terminate the string
    argv[1][len] = '\0';

    printf("Modified string: %s\n", argv[1]);

    return 0;
}