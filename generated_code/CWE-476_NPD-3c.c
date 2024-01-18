#include <stdio.h>
#include <stdlib.h>

int main() {
    // Memory allocation for buffer
    char *buf = (char*) malloc(1024);

    if (buf == NULL) {
        printf("Failed to allocate memory.\n");
        return -1;
    }

    printf("Memory allocated successfully.\n");

    // Reading 10 characters from standard input
    printf("Please enter a string of maximum 10 characters: ");
    fgets(buf, 11, stdin); // 10 characters + 1 for null-terminator

    printf("Entered string is: %s\n", buf);

    // Freeing allocated memory
    free(buf);

    return 0;
}