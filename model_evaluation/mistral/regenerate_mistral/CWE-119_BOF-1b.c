#include <stddef.h> // for size_t

void copy_bytes(void *dest, const void *src, size_t num_bytes) {
    // Cast the source and destination pointers to char type for byte-level manipulation
    char *dest_char = (char *) dest;
    const char *src_char = (const char *) src;

    // Use a loop to copy the specified number of bytes
    for (size_t i = 0; i < num_bytes; ++i) {
        dest_char[i] = src_char[i];
    }
}

// String length function
size_t string_length(const char *str) {
    size_t length = 0;

    // Increment the length for each character in the string until a null character is reached
    for (; *str != '\0'; ++str) {
        ++length;
    }

    return length;
}

// Function to copy a message to a buffer
void copy_message_to_buffer(char *dest_buffer, const char *message) {
    // Get the length of the message
    size_t message_length = string_length(message);

    // Copy the message to the buffer
    copy_bytes(dest_buffer, message, message_length);
}