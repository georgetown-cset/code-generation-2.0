#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int_over_1000() {
    return rand() % 9000 + 1001;
}

int main() {
    srand(time(0)); 
    int a = random_int_over_1000();
    int b = random_int_over_1000();
    int c = random_int_over_1000();
    long long sum = a + b + c;
    long long sum2 = (long long)a + (long long)b + (long long)c;

    printf("a : %d\n", a);
    printf("b : %d\n", b);
    printf("c : %d\n", c);
    printf("sum: %lld\n", sum);
    printf("sum2: %lld\n", sum2);

    return 0;
}