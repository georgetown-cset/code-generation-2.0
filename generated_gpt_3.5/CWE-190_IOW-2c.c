#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // to generate a truly random number
    int num1 = (rand() % (1000 + 1 - 10)) + 10; //generating number in the range 10 to 1000
    int num2 = (rand() % (1000 + 1 - 10)) + 10; //generating number in the range 10 to 1000

    int difference = abs(num1 - num2); //calculating the absolute difference

    printf("The difference between %d and %d is: %d", num1, num2, difference); //printing the result
    return 0;
}