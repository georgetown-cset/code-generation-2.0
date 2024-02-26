#include <stdio.h>
#define buffer_size 10

int main() {
    char buffer[buffer_size]; // Allocate buffer on the stack

    // Initialize all elements of the buffer with 'A'
    for (size_t i = 0; i < buffer_size; i++) {
        buffer[i] = 'A';
    }

    // Print some elements for verification
    for (size_t i = 0; i < 5; i++) {
        printf("Buffer[%ld] = %c\n", i, buffer[i]);
    }

    return 0;
}