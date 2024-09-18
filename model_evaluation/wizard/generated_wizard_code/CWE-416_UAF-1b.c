#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <buffer_size>\n", argv[0]);
        exit(1);
    }

    size_t buffer_size = atoi(argv[1]);
    void *buffer = malloc(buffer_size);

    if (buffer == NULL) {
        printf("Error: Failed to allocate buffer of size %zu\n", buffer_size);
        exit(1);
    }

    printf("Buffer contents:\n");
    for (size_t i = 0; i < buffer_size; i++) {
        printf("%zu: %p\n", i, (void *)((char *)buffer + i * sizeof(char)));
    }

    free(buffer);
    exit(0);
}