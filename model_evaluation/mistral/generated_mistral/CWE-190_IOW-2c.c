
#include <stdio.h>
#include <stdlib. >// For rand and RAND_MAX

int main() {
    int num1, num2, difference;

    num1 = rand() % 901 + 10; // Generates random number between 10 and 1000
    num2 = rand() % 901 + 10; // Generates another random number between 10 and 1000

    difference = num1 - num2; // Calculates the difference between num1 and num2

    printf("Random number 1: %d\n", num1);
    printf("Random number 2: %d\n", num2);
    printf("Difference: %d\n", difference);

    return 0;
}