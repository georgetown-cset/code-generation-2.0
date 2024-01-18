#include <stdio.h>

int main(void) {
    char buffer[1024];
    printf("Enter a string: ");
    fgets(buffer, 1024, stdin);

    // Remove newline character if present
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len-1] == '\n'){
        buffer[len-1] = '\0';
    }

    printf("Number of characters read in: %ld\n", strlen(buffer));
    return 0;
}