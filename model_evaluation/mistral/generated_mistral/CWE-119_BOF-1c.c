#include <stddef.h> // For size_t
#include <string.h> // For strlen()

// Function to copy 'n' bytes from 'src' to 'dest'
void copy_memory(void* dest, const void* src, size_t n) {
    memcpy(dest, src, n);
}

// Function to copy the string "Hello" to a given buffer
#define BUFFER_SIZE 6 // Ensure the buffer is large enough to hold "Hello" plus a null terminator
void copy_string_to_buffer(char buffer[]) {
    const char source[] = "Hello";
    size_t string_length = strlen(source); // Get the length of the string "Hello"

    // Check if the buffer is large enough to hold the string "Hello" and a null terminator
    if (sizeof(buffer) < string_length + 1) {
        // Handle error, e.g., print an error message or terminate the program
        printf("Buffer is too small.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the string "Hello" to the buffer
    copy_memory(buffer, source, string_length);
    buffer[string_length] = '\0'; // Add a null terminator
}