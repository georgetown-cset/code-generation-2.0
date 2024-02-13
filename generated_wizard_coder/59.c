#include <stdio.h>
#include <stdlib.h>

int main() {
    int buffer_size;
    printf("Enter the size of the buffer: ");
    scanf("%d", &buffer_size);

    char buffer[buffer_size];

    // Overwrite all values in the buffer with 'A'
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 'A';
    }

    printf("Buffer contents: ");
    for (int i = 0; i < buffer_size; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    return 0;
}