#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int array[] = {10, 20, 30, 40, 50};
    int num;

    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    num = atoi(argv[1]);

    if (num >= 0 && num < sizeof(array)/sizeof(array[0])) {
        printf("Element at index %d is: %d\n", num, array[num]);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}