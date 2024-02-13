#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void floatToString(float num, char* str);

int main() {
    srand(time(NULL));

    float a = (float)rand() / RAND_MAX;
    float b = (float)rand() / RAND_MAX;
    float c = (float)rand() / RAND_MAX;

    char str_a[50];
    char str_b[50];
    char str_c[50];

    floatToString(a, str_a);
    floatToString(b, str_b);
    floatToString(c, str_c);

    printf("str_a: %s\n", str_a);
    printf("str_b: %s\n", str_b);
    printf("str_c: %s\n", str_c);

    return 0;
}

void floatToString(float num, char* str) {
    sprintf(str, "%.2f", num);
}