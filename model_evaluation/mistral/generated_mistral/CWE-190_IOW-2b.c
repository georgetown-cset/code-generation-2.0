
#include <stdio.h>
#include <stdlib.h> // For rand and RAND_MAX

int main() {
    int a, b, c; // Declare three integer variables
    long long sum, sum2; // Declare two long long variables for summation

    // Generate three random integers larger than 1000
    a = rand() % 6001 + 1001;
    b = rand() % 6001 + 1001;
    c = rand() % 6001 + 1001;

    // Print the three integers
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    printf("c : %d\n", c);

    // Add the three integers
    sum = a + b + c;
    printf("sum: %d\n", sum);

    // Add the three integers using a long long and print the result
    sum2 = (long long) a + (long long) b + (long long) c;
    printf("sum2: %lld\n", sum2);

    return 0;
}