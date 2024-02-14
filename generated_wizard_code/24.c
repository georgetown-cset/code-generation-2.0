#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two random integers between 10 and 1000
    int num1 = rand() % 901 + 10;
    int num2 = rand() % 901 + 10;

    // Calculate the difference between the two integers
    int difference = num1 - num2;

    // Print the results
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);
    printf("Difference: %d\n", difference);

    return 0;
}