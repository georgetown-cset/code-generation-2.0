#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s index\n", argv[0]);
        return 1;
    }

    int index = atoi(argv[1]);
    if (index < 1 || index > argc) {
        printf("Invalid index\n");
        return 1;
    }

    printf("The %d-th argument is: %s\n", index, argv[index]);
    return 0;
}