
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    int y;

    if (argc!= 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        exit(1);
    }

    x = atoi(argv[1]);
    y = x + 1000;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
