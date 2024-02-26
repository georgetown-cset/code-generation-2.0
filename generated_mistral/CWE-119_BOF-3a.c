#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int index, second_arg_index, integer_value;

    if (argc < 3) {
        printf("Usage: %s <second_argument> <index>\n", argv[0]);
        return 1;
    }

    index = atoi(argv[1]);
    second_arg_index = atoi(argv[2]);

    if (index < 0 || index >= argc) {
        printf("Invalid index\n");
        return 1;
    }

    printf("The value at index %d in command line arguments is: %s\n", second_arg_index, argv[index + second_arg_index]);

    integer_value = atoi(argv[index + second_arg_index]);
    printf("The integer value at index %d + index %d is: %d\n", index, second_arg_index, integer_value);

    return 0;
}