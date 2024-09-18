#include <stdio.h> // Include the standard library
#include "my_function.h" // Include a local header file

int main() {
    int num = 5;

    printf("The square of %d is: %d\n", num, square(num));

    return 0;
}