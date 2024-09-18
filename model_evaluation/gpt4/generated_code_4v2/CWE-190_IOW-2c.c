#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* Initialize random number generator */
    srand(time(0));

    int number1 = rand() % 991 + 10; /* generates a random integer between 10 and 1000 */
    int number2 = rand() % 991 + 10; /* generates a random integer between 10 and 1000 */

    int difference = abs(number1 - number2); /* calculates the difference between the two integers */

    printf("First number: %d\n", number1);
    printf("Second number: %d\n", number2);
    printf("The difference is: %d\n", difference); /* prints the results */

    return 0;
}