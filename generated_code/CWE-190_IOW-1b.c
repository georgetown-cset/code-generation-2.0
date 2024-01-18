#include <stdio.h>
#include <stdlib.h>

const int OFFSET = 1000;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a number as command line argument\n");
        return 1;
    }

    int value = atoi(argv[1]);
    value += OFFSET;

    printf("After adding offset, the value is: %d\n", value);

    return 0;
}