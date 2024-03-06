
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    float a, b, c;
    char str_a[100], str_b[100], str_c[100];

    srand(time(NULL));

    a = rand() % 100;
    b = rand() % 100;
    c = rand() % 100;

    sprintf(str_a, "%f", a);
    sprintf(str_b, "%f", b);
    sprintf(str_c, "%f", c);

    a = atof(str_a);
    b = atof(str_b);
    c = atof(str_c);

    printf("%f %f %f\n", a, b, c);
}
