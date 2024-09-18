
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
  int file_descriptor;
  char important_config[] = "This is an important configuration.";

  file_descriptor = open("config.txt", O_RDWR | O_CREAT, 0700);

  if (file_descriptor < 0) {
    perror("Error opening file.");
    return 1;
  }

  ssize_t bytes_written = write(file_descriptor, important_config, sizeof(important_config));

  if (bytes_written < 0) {
    perror("Error writing to file.");
    close(file_descriptor);
    return 1;
  }

  printf("Successfully wrote %ld bytes to file.\n", bytes_written);

  close(file_descriptor);
  return 0;
}