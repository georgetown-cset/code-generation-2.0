#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Exactly one argument is required.\n");
        return -1;
    }

    char* input = argv[1];
    printf("Original argument: %s\n", input);

    // Perform the trimming (from the end)
    int len = strlen(input);
    while(len > 0 && isspace(input[len-1])) {
        input[--len] = '\0';
    }

    printf("Trimmed argument: %s\n", input);

    return 0;
}