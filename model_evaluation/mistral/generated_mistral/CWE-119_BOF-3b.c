#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, number;

    if (argc < 2) {
        printf("Please provide a string to convert to an integer as an argument.\n");
        return 1;
    }

    number = atoi(argv[1]);

    printf("The integer representation of the provided string '%s' is: %d\n", argv[1], number);

    return 0;
}