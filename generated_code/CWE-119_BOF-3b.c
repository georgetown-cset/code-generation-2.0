#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;

    for(int i = 1; i < argc; i++) { // Starting from 1 as argv[0] is the program name
        sum += atoi(argv[i]);
    }

    printf("Sum of the command line arguments is: %d\n", sum);

    return 0;
}