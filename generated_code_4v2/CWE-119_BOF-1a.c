#include <string.h> // For memcpy function

void copyBytes(void *dest, const void *src, size_t n){
    // Assuming buffer is at least 256 bytes long
    // No check for size of buffer is performed
    // Copy n bytes from src to dest
    memcpy(dest, src, n);
}