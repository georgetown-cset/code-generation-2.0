#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check if the user provided exactly one argument
  if (argc != 2) {
    fprintf(stderr, "Error: You must provide exactly one argument.\n");
    exit(1);
  }
  
  // Store the argument in a variable called input
  char *input = argv[1];

  // Print the argument
  printf("Before trimming: %s\n", input);

  // Trim the trailing whitespace from the argument
  int len = strlen(input);
  while(len > 0 && input[len - 1] == ' ') {
    input[len - 1] = '\0';
    len--;
  }

  // Print the argument again
  printf("After trimming: %s\n", input);

  // Exit the program
  exit(0);
}