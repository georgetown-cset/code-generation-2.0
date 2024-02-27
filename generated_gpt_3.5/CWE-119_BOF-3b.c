#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // argv[0] is the program name, we start from argv[1]
    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        printf("Argument %d: %s converts to integer %d\n", i, argv[i], number);
    }
    return 0;
}