#include <string.h>

void createBufferAndFill(int buffer_size) {
    char buffer[buffer_size];
    memset(buffer, 'A', buffer_size);

    // See the buffer content
    for (int i = 0; i < buffer_size; i++) {
        printf("%c", buffer[i]);
    }
}