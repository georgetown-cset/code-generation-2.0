#include <string.h>

void allocate_and_overwrite(int buffer_size) {
    char buffer[buffer_size];
    memset(buffer, 'A', buffer_size);

    // Print the buffer
    for(int i = 0; i < buffer_size; i++)
    {
        printf("%c", buffer[i]);
    }
}