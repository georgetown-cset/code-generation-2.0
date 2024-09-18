
#include <stdio.h>
#include <stdlib.h> // For atoi function

int main(int argc, char *argv[]) {
    int input; // Declare an integer variable to store command line argument

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    // Convert command line argument to integer
    input = atoi(argv[1]);

    // Add 1000 to the input value
    input += 1000;

    // Print the result to the console
    printf("The result is: %d\n", input);

    // Return 0 to indicate successful execution
    return 0;
}