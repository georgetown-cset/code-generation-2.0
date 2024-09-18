#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void floatToString(float f, char* buffer) {
    // We will convert float to string by using sprintf
    sprintf(buffer, "%.6f", f);
}

int main() {
    char str_a[20], str_b[20], str_c[20];
    float a, b, c;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    // Generate three random floats in the range 0 to 1
    a = (float)rand() / RAND_MAX;
    b = (float)rand() / RAND_MAX;
    c = (float)rand() / RAND_MAX;

    // Convert them to strings
    floatToString(a, str_a);
    floatToString(b, str_b);
    floatToString(c, str_c);

    // Print the strings
    printf("str_a: %s\n", str_a);
    printf("str_b: %s\n", str_b);
    printf("str_c: %s\n", str_c);

    return 0;
}