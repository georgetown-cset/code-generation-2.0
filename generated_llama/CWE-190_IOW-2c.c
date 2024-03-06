
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
    printf("a = %d, b = %d, diff = %d\n", a, b, diff);
    return 0;
}
