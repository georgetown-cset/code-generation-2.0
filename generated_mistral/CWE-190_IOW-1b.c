#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    // Convert the command line argument to an integer
    int value = atoi(argv[1]);

    // Add the offset to the value
    int result = value + 1000;

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}