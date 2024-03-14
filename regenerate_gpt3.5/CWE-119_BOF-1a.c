#include <stdio.h>

void copy_bytes(char *dest, char *src, size_t num_bytes) {
    for (size_t i = 0; i < num_bytes; i++) {
        dest[i] = src[i];
    }
}

int main() {
    char dest[256];
    char src[] = "Hello, world!";
    size_t num_bytes = sizeof(src);

    copy_bytes(dest, src, num_bytes);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}