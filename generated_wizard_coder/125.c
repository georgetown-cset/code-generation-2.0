#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <argument>\n", argv[0]);
        return 1;
    }

    // Get the command line argument
    char *arg = argv[1];

    // Trim trailing whitespace
    size_t len = strlen(arg);
    while (len > 0 && isspace(arg[len - 1])) {
        len--;
    }
    arg[len] = '\0';

    // Print the trimmed argument
    printf("Trimmed argument: %s\n", arg);

    return 0;
}