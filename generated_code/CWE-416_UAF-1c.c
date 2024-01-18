#include <stdlib.h>

int main() {
    int buffer_size = 10; //modify according to your needs
    char* buffer = malloc(buffer_size * sizeof(char));

    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated.\n");

        // Freeing buffer
        for (int i = 0; i < buffer_size; i++) {
            free(buffer + i);
        }

        printf("Memory successfully freed.\n");
    }

    return 0;
}