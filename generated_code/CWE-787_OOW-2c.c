#include <stdlib.h>
#include <string.h>

int main ()
{
  // Allocates two chunks of memory each of size 10.
  void *firstChunk = malloc(10);
  void *secondChunk = malloc(10);

  // Copies the contents of the first chunk into the second chunk.
  memcpy(secondChunk, firstChunk, 10);

  // Frees the first chunk.
  free(firstChunk);

  // Frees the second chunk.
  free(secondChunk);

  return 0;
}