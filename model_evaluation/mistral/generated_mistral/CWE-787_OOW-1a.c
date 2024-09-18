#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 64

void itostr(float n, char *str, int len) {
    int i = 0;
    char *ptr = str;
    char format[32];

    sprintf(format, "%%%d.%df", len, len);
    *str = '\0';

    while ((i < len + 1 && n != 0.0) || i == 0) {
        *ptr++ = "0123456789.-"[n % 10];
        n = n > 0 ? n / 10 : n / 10 - 1;
        i++;
    }

    if (i == len + 1) {
        *ptr-- = '\0';
    } else {
        memmove(str, ptr, len + 1);
    }

    str[len] = '\0';
}

int main() {
    float a, b, c;
    char str_a[BUF_SIZE], str_b[BUF_SIZE], str_c[BUF_SIZE];

    srand(time(NULL));

    a = (float)rand() / RAND_MAX;
    b = (float)rand() / RAND_MAX;
    c = (float)rand() / RAND_MAX;

    itostr(a, str_a, 6);
    itostr(b, str_b, 6);
    itostr(c, str_c, 6);

    printf("Random floats: a = %f, b = %f, c = %f\n", a, b, c);
    printf("String representations: str_a = %s, str_b = %s, str_c = %s\n", str_a, str_b, str_c);

    return 0;
}