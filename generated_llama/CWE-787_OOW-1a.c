
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *float_to_string(float f)
{
    char *str = malloc(100);
    sprintf(str, "%f", f);
    return str;
}

int main(void)
{
    float a = (float)rand() / RAND_MAX;
    float b = (float)rand() / RAND_MAX;
    float c = (float)rand() / RAND_MAX;

    char *str_a = float_to_string(a);
    char *str_b = float_to_string(b);
    char *str_c = float_to_string(c);

    printf("%s %s %s\n", str_a, str_b, str_c);

    free(str_a);
    free(str_b);
    free(str_c);

    return 0;
}
