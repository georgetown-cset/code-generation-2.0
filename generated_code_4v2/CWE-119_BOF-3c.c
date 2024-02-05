#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  
    // Check if the user has entered an index
    if (argc < 2) {
        printf("Please provide an index as an argument.\n");
        return 1;
    }

    // Convert the first argument to an integer
    int index = atoi(argv[1]);

    // Check if the index provided is within the range
    if (index >= argc-1 || index < 0) {
        printf("Index out of bounds. Please ensure you've provided enough arguments and index is not negative.\n");
        return 1;
    }

    // Print the argument corresponding to the provided index
    printf("The argument at index %d is: %s\n", index, argv[index+2]);

    return 0;
}