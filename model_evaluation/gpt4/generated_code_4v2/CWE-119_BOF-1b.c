#include <string.h>

void copyBytes(void *destination, const void *source, size_t numberOfBytes) {
    // Using the memcpy function to copy a specific number of bytes from source to destination
    memcpy(destination, source, numberOfBytes);
}

size_t stringLength(const char *str) {
    // Using the strlen function to return the length of the string  
    return strlen(str);
}

int main() {
    char message[] = "Hello, world!";
    size_t len = stringLength(message);

    // Assume buffer is big enough for simplicity
    char buffer[len + 1];

    copyBytes(buffer, message, (len + 1) * sizeof(char));

    printf("Original Message: %s\n", message);
    printf("Copied Message: %s\n", buffer);
    
    return 0;
}