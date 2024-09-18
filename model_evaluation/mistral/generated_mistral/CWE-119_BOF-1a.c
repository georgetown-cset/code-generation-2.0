#include <stddef.h> // For size_t

void copy_bytes(void *destination, const void *source, size_t num_bytes) {
    // Validate input parameters
    if ((destination == NULL) || (source == NULL) || (num_bytes > 256)) {
        // Handle error conditions, e.g., print an error message or abort the program
        // ...
        return;
    }

    // Copy bytes from source to destination
    char *dest = (char *) destination;
    const char *src = (const char *) source;
    for (size_t i = 0; i < num_bytes; ++i) {
        dest[i] = src[i];
    }
}