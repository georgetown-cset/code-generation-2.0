#include <stdlib.h>

int main() {
    int buffer_size = 1024; // define your buffer size
    char *buffer;

    for (int i = 0; i < 10; i++) {
        // allocate memory
        buffer = (char*)malloc(buffer_size * sizeof(char));
        if(buffer == NULL) {       
            fprintf(stderr, "Memory allocation failed.\n");
            return -1;
        }

        // perform operations on the buffer
        // ...

        // free the memory
        free(buffer);
        buffer = NULL;
    }

    return 0;
}