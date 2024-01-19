#include <string.h>

void copyBytes(void* dest, const void* src, size_t n) {
    if (n > 256) {
        printf("Error: Number of bytes to copy exceeds buffer size.\n");
        return;
    }
    
    memcpy(dest, src, n);
}