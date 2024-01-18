#include <string.h>

// Copy function
void copyBytes(void *destination, const void *source, size_t n) {
    // Using memory function memcpy to copy bytes from source to destination
    memcpy(destination, source, n);
}

// String length function
size_t stringLength(const char *str) {
    // Using string function strlen to get the length of the string
    return strlen(str);
}

int main() {
    char message[] = "This is sample message";
    char buffer[100];
    // Calling copy function
    copyBytes(buffer, message, stringLength(message)+1);
    printf("Copied message: %s\n", buffer);
    return 0;
}