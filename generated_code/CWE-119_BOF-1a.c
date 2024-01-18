#include <string.h>

#define BUFFER_SIZE 256

void copy_memory(void *dst, const void *src, size_t num_bytes) {
  if (num_bytes > BUFFER_SIZE) {
    printf("Error: Attempted to copy too many bytes. Buffer size is %d bytes.\n", BUFFER_SIZE);
    return;
  }
  
  memcpy(dst, src, num_bytes);
}