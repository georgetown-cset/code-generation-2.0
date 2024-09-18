#include <stdlib.h>

int main() {
    
    size_t buffer_size = 64; // set appropriate buffer size
    char *buffer = (char*)malloc(sizeof(char) * buffer_size);

    if (buffer == NULL) {
        // insufficient memory
        return -1;
    }

    for(size_t i = 0; i < buffer_size; i++) {
        buffer[i] = 0; // clean buffer
    }

    free(buffer); // free the buffer
    
    return 0;
}