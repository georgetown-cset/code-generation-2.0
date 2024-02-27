#include <stdlib.h>
#include <string.h>

void alloc_buffer_and_fill(size_t buffer_size) {
    char buffer[buffer_size];

    // Fill buffer with 'A'
    memset(buffer, 'A', buffer_size);

    // ... you can use the buffer here...

    // The buffer will automatically be deallocated when the function returns
    // because it was allocated on the stack.
}