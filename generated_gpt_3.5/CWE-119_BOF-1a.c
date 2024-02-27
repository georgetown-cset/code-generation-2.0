#include <string.h>

#define BUFFER_SIZE 256

void copy_bytes(void *dest, const void *src, size_t n){
    // Ensure the number of bytes to copy does not exceed the buffer size
    if (n > BUFFER_SIZE){
        // Handle error. Here, we just print an error message and return
        printf("Error: Number of bytes to copy exceeds buffer size.\n");
        return;
    }

    // Use memcpy to copy bytes from src to dest
    memcpy(dest, src, n);
}