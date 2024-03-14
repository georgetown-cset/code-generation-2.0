#include <stdlib.h>

#define BUFFERSIZE 1024 // Change this to the desired buffer size

int main() {
    // Allocate the buffer
    char *buffer = (char *)malloc(BUFFERSIZE * sizeof(char));
    if(!buffer) {
        perror("Failed to allocate memory");
        return -1;
    }
    
    for(int i = 0; i < 100; i++) { // adjust loop count as needed
        // Free the buffer
        free(buffer);

        // Reallocate the buffer
        buffer = (char *)malloc(BUFFERSIZE * sizeof(char));
        if(!buffer) {
            perror("Failed to allocate memory");
            return -1;
        }
    }

    // Finally free the buffer
    free(buffer);
    
    return 0;
}