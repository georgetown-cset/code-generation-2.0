#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc < 3) {
        printf("Usage: %s index\n", argv[0]);
        return 1;
    }

    // Convert the index from string to integer
    int index = atoi(argv[1]);

    // Check if the index is within the range of command line arguments
    if (index < 1 || index > argc) {
        printf("Invalid index\n");
        return 1;
    }

    // Print the string at the specified index
    printf("Argument at index %d: %s\n", index, argv[index]);

    // Return 0 to indicate successful execution
    return 0;
}