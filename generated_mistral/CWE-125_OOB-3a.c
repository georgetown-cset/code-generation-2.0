#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main(int argc, char *argv[]) {
    int arr[ARRAY_SIZE] = {0}; // initialize an array of size 10 with zeroes
    int input, index;

    printf("Enter an integer: ");
    scanf("%d", &input);

    if (input == -1) {
        printf("Returning -1\n");
    } else {
        index = input < 0 ? ARRAY_SIZE + input : input; // handle negative input
        if (index >= ARRAY_SIZE) {
            printf("Index out of bounds, returning -1\n");
            index = -1;
        } else {
            printf("The value at index %d is %d\n", input, arr[index]);
            printf("Returning the value at index %d\n", index);
        }
    }

    printf("Exiting program\n");
    return 0;
}