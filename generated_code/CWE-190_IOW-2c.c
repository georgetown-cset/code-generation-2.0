#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>    

int main() {
    srand(time(0));   // Initialization of random seed

    // Generate two random numbers between 10 and 1000
    int num1 = (rand() % 991) + 10;
    int num2 = (rand() % 991) + 10;

    // Calculate the difference between the two numbers
    int diff = abs(num1 - num2);

    // Print the result
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);
    printf("Difference is: %d\n", diff);

    return 0;
}