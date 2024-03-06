
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, diff;
    srand(time(NULL));
    a = rand() % 900 + 10;
    b = rand() % 900 + 10;
    diff = a - b;
    printf("The difference between %d and %d is %d\n", a, b, diff);
    return 0;
}
