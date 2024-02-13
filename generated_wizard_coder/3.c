#include <stdio.h>
#include <string.h>

void copy_memory(char *destination, char *source, int num_bytes) {
    for (int i = 0; i < num_bytes; i++) {
        destination[i] = source[i];
    }
}

int main() {
    char buffer[20];
    char *string = "Hello";
    int string_length = strlen(string);

    copy_memory(buffer, string, string_length);

    printf("Copied string: %s\n", buffer);

    return 0;
}