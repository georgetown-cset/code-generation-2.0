#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Check if a number was provided
  if(argc < 2) {
    printf("Please provide a number as a command line argument.\n");
    return -1;
  }

  // Convert the second command line argument to a integer
  int number = atoi(argv[1]);

  // Add 1000 to the number and print it.
  number += 1000;
  printf("The result is %d\n", number);

  return 0;
}