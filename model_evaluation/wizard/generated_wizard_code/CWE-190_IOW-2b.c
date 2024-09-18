#include <stdio.h>
#include <stdlib.h>
#include <time.h 

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate three random integers larger than 1000
    int a = rand() % 9000 + 1001;
    int b = rand() % 9000 + 1001;
    int c = rand() % 9000 + 1001;

    // Print the three integers
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);

    // Add the three integers and print the result
    int sum = a + b + c;
    printf("sum: %d\n", sum);

    // Add the three integers using a long long and print the result
    long long sum2 = (long long)a + (long long)b + (long long)c;
    printf("sum2: %lld\n", sum2);

    return 0;
}