
#include <stdio.h> // for printf and argc, argv
#include <stdlib.h> // for atoi

int main(int argc, char *argv[]) {
  int input; // variable to store input value

  // Check if the correct number of arguments is provided
  if (argc != 2) {
    printf("Usage: %s <integer>\n", argv[0]);
    return 1;
  }

  // Convert command line argument to integer
  input = atoi(argv[1]);

  // Add 1000 to the input value
  input += 1000;

  // Print the result
  printf("The result is: %d\n", input);

  return 0;
}