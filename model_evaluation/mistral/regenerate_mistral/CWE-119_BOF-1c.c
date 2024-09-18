#include <stddef.h>
#include <string.h> // For strlen function

// Function to copy a specified number of bytes from source to destination
void memcpy_bytes(void *dest, const void *src, size_t num_bytes) {
    memcpy(dest, src, num_bytes);
}

// Function to calculate the length of a string (assuming null-terminated)
size_t strlen_custom(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Main function to copy the string "Hello" to a buffer
int main() {
    char buffer[6]; // Allocate enough space for the string "Hello" and a null terminator

    // Initialize the string "Hello"
    const char source[] = "Hello";

    // Copy the string "Hello" to the buffer using memcpy_bytes
    memcpy_bytes(buffer, source, strlen_custom(source) + 1);

    // Print the copied string
    printf("Copied string: %s\n", buffer);

    return 0;
}