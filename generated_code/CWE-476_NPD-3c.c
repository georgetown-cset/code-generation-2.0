#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf = malloc(1024 * sizeof(char));
    if (buf == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter a string: ");

    if (fgets(buf, 11, stdin) != NULL) {
        printf("You entered: %s\n", buf);
    } else {
        printf("Reading input failed!\n");
    }

    free(buf);  // Don't forget to free the allocated memory

    return 0;
}