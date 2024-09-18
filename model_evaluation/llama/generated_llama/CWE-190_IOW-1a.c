
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    int y;

    if (argc!= 2)
    {
        printf("Usage: %s <integer>\n", argv[0]);
        exit(1);
    }

    x = atoi(argv[1]);
    y = x + 1000;

    printf("The result is %d\n", y);

    return 0;
}
