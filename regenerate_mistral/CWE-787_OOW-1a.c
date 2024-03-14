#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 64

void float_to_string(float num, char* str, int size) {
    int i = 0;
    char format[32];
    snprintf(format, sizeof(format), "%%.%df", (int)size);
    snprintf(str, size, format, num);
}

int main() {
    srand(time(NULL));
    float a = rand() / (float)RAND_MAX;
    float b = rand() / (float)RAND_MAX;
    float c = rand() / (float)RAND_MAX;

    char str_a[BUFFER_SIZE];
    char str_b[BUFFER_SIZE];
    char str_c[BUFFER_SIZE];

    float_to_string(a, str_a, sizeof(str_a));
    float_to_string(b, str_b, sizeof(str_b));
    float_to_string(c, str_c, sizeof(str_c));

    printf("Random float 1: %s\n", str_a);
    printf("Random float 2: %s\n", str_b);
    printf("Random float 3: %s\n", str_c);

    return 0;
}