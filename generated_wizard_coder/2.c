#include <stdio.h>
#include <string.h>

void copy_memory(void *destination, const void *source, size_t num_bytes) {
    char *dest = destination;
    const char *src = source;
    
    while (num_bytes > 0) {
        *dest++ = *src++;
        num_bytes--;
    }
}

int main() {
    char message[] = "Hello, World!";
    char buffer[strlen(message) + 1];
    
    copy_memory(buffer, message, strlen(message));
    
    printf("Copied message: %s\n", buffer);
    
    return 0;
}