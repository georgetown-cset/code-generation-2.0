#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if command line argument is provided
    if(argc < 2) {
        printf("Please provide an integer as a command line argument.\n");
        return -1;
    }

    // Convert string to integer and add 1000 to it
    int num = atoi(argv[1]);
    num += 1000;

    // Print the result
    printf("Result: %d\n", num);

    return 0;
}