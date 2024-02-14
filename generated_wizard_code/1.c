#include <stdio.h>

void copy_memory(char *destination, char *source, int num_bytes) {
    for (int i = 0; i < num_bytes; i++) {
        destination[i] = source[i];
    }
}

int main() {
    char buffer[256];
    char message[] = "Hello, world!";

    copy_memory(buffer, message, sizeof(message));

    printf("Copied message: %s\n", buffer);

    return 0;
}