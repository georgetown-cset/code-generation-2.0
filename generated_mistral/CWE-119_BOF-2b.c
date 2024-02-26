
#include <stdio.h>
#define SIZE 10

int main(int argc, char *argv[]) {
    int arr[SIZE]; // define an array of size 10
    int index, num;

    if (argc != 2) { // check if command line argument is provided
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d", &num); // convert command line argument to integer

    if (sscanf(argv[1], "%d", &num) != 1 || num < 0 || num >= SIZE) { // check if conversion successful and input is within array bounds
        printf("invalid input\n");
    } else {
        printf("Element at index %d: %d\n", num, arr[num]);
    }

    return 0;
}

// Compile with: gcc code.c -o code