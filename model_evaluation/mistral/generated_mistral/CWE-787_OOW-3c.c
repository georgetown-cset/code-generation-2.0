
#include <stdio.h>
#include <stdlib.h> // for malloc and realloc
#include <string.h> // for strlen and memmove

int main(int argc, char *argv[]) {
    if (argc < 2) { // check if argument is provided
        printf("Error: Please provide a command line argument.\n");
        return 1;
    }

    size_t size = strlen(argv[1]) + 1; // allocate memory for the argument plus null terminator
    char *arg_copy = (char *) malloc(size); // allocate memory for a copy of the argument

    if (arg_copy == NULL) { // check for memory allocation error
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    strcpy(arg_copy, argv[1]); // copy the argument into the allocated memory

    size_t i = strlen(arg_copy); // get the length of the argument

    // trim trailing whitespace
    while (i > 0 && isspace(arg_copy[i - 1])) {
        arg_copy[i - 1] = '\0'; // replace trailing whitespace with null terminator
        i--;
        size--; // adjust size of the allocated memory
    }

    // move the non-trailing whitespace characters to the end of the string and add a null terminator
    memmove(arg_copy + (i), arg_copy + i, size - i);
    arg_copy[size - 1] = '\0';

    printf("Argument: %s\n", arg_copy); // print the trimmed argument

    free(arg_copy); // free the allocated memory
    return 0;
}