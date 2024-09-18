#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE 1000

int main() {
    srand(time(NULL));
    int a = rand() % (RAND_MAX - MIN_VALUE) + MIN_VALUE;
    int b = rand() % (RAND_MAX - MIN_VALUE) + MIN_VALUE;
    int c = rand() % (RAND_MAX - MIN_VALUE) + MIN_VALUE;
    
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    printf("c : %d\n", c);

    int sum = a + b + c;
    printf("sum: %d\n", sum);

    long long a_ll = a;
    long long b_ll = b;
    long long c_ll = c;
    long long sum2 = a_ll + b_ll + c_ll;

    printf("sum2: %lld\n", sum2);
    
    return 0;
}