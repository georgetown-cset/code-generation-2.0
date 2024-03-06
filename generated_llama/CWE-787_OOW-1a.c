
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

void convert_string_to_float(char *string, float *float_value)
{
    *float_value = atof(string);
}

void convert_float_to_string(float float_value, char *string)
{
    sprintf(string, "%f", float_value);
}

int main(void)
{
    char str_a[MAX_STRING_LENGTH];
    char str_b[MAX_STRING_LENGTH];
    char str_c[MAX_STRING_LENGTH];

    float a;
    float b;
    float c;

    srand(time(NULL));

    a = (float)rand() / (float)(RAND_MAX);
    b = (float)rand() / (float)(RAND_MAX);
    c = (float)rand() / (float)(RAND_MAX);

    convert_float_to_string(a, str_a);
    convert_float_to_string(b, str_b);
    convert_float_to_string(c, str_c);

    convert_string_to_float(str_a, &a);
    convert_string_to_float(str_b, &b);
    convert_string_to_float(str_c, &c);

    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);

    return 0;
}
