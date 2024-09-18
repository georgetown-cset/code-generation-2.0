#include <string.h> 

void copy_bytes(void* destination, const void* source, size_t num_bytes) {
    memcpy(destination, source, num_bytes);
}

size_t string_length(char* str) {
    return strlen(str);
}

int main() {
    char message[] = "Hello, world!";
    size_t message_length = string_length(message);
    char buffer[message_length + 1]; // +1 for the null character

    copy_bytes(buffer, message, message_length + 1); // +1 to include the null character

    printf("Copied string: %s\n", buffer);

    return 0;
}