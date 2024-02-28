
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c;
    srand(time(NULL));
    a = rand() % 900 + 10;
    b = rand() % 900 + 10;
    c = a - b;
    printf("%d", c);
    return 0;
}
