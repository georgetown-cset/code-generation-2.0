#include <stdio.h>
#include <string.h>

void copyBytes(char *destination, const char *source, size_t numBytes) {
    // Copy the bytes.
    memcpy(destination, source, numBytes);
}

size_t stringLength(const char *source) {
    // Return the length of the string.
    return strlen(source);
}

int main() {
    // Define a buffer and the string to copy.
    char buffer[100];
    const char *source = "Hello";

    // Calculate the length of the source string.
    size_t length = stringLength(source);

    // Copy the string to the buffer.
    copyBytes(buffer, source, length);

    // Null terminate the buffer string.
    buffer[length] = '\0';

    // Print the buffer.
    printf("%s\n", buffer);
    return 0;
}