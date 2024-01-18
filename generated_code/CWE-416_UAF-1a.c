#include <string.h>  

void allocate_buffer_and_overwrite(size_t buffer_size) {
    char buffer[buffer_size];
    memset(buffer, 'A', buffer_size);
    
    // Buffer is auto destroyed after this function is returned
}