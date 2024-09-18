#include <stddef.h> // For size_t

void copy_bytes(void *dest, const void *src, size_t num_bytes) {
    // Cast src and dest to char pointers since we're dealing with bytes
    char *dest_char = (char *) dest;
    const char *src_char = (const char *) src;

    // Use a for loop to copy each byte
    for (size_t i = 0; i < num_bytes; ++i) {
        dest_char[i] = src_char[i];
    }
}

// String length function using the standard library
size_t string_length(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

// Function to copy a message to a buffer
void copy_message_to_buffer(char *dest_buffer, const char *message) {
    size_t message_length = string_length(message);
    copy_bytes(dest_buffer, message, message_length);
}