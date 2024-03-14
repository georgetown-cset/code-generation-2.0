#include <stdio.h>
#include <stdlib.h>

#define buffer_size 100

int main() {
    char buffer[buffer_size];
    int i;

    // Fill buffer with 'A'
    for (i = 0; i < buffer_size; i++) {
        buffer[i] = 'A';
    }

    // Print buffer contents
    for (i = 0; i < buffer_size; i++) {
        printf("%c", buffer[i]);
    }

    return 0;
}