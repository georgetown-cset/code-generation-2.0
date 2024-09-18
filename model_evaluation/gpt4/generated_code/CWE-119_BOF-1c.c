#include <string.h>

void memory_copy(void* dest, const void* src, size_t num) {
    char* cdest = (char*) dest;
    const char* csrc = (const char*) src;

    for (size_t i = 0; i < num; i++) {
        cdest[i] = csrc[i];
    }
}

size_t string_length(const char* str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

int main() {
    const char* src = "Hello";
    char buffer[100];

    size_t num = string_length(src) + 1; // +1 for NULL terminator
    memory_copy(buffer, src, num);

    return 0;
}