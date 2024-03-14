#include <stddef.h> // for size_t

void copy_bytes(void *dest, const void *src, size_t num_bytes) {
    // Validate input arguments
    if ((dest == NULL) || (src == NULL) || (num_bytes > 256)) {
        // Handle error condition (e.g., print an error message and exit)
        return;
    }

    // Use memmove function from string.h to copy bytes
    memmove(dest, src, num_bytes);
}