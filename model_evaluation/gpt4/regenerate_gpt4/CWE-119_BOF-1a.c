#include <string.h>

#define BUFF_SIZE 256

void copyMemory(void* destination, const void* source, size_t numBytes) {
    // Ensure that the number of bytes to copy won't overrun the buffer
    if (numBytes > BUFF_SIZE) {
        numBytes = BUFF_SIZE;
    }
    
    // Copy memory 
    memcpy(destination, source, numBytes);
}