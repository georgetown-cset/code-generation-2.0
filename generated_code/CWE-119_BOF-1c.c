#include <stdio.h>
#include <string.h>

void copy_bytes(char* dest, const char* src, size_t n) {
    memcpy(dest, src, n);
}

size_t string_length(const char* str) {
    return strlen(str);
}

int main() {
    const char* str = "Hello";
    size_t len = string_length(str);
    char buffer[len + 1];
    copy_bytes(buffer, str, len);
    buffer[len] = '\0'; // null terminate the string
    printf("Copied string: %s\n", buffer);
    return 0;
}