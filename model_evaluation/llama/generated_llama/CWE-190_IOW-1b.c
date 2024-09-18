
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int value;
    int offset = 1000;

    if (argc!= 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        exit(1);
    }

    value = atoi(argv[1]);
    value += offset;

    printf("The value is %d\n", value);

    return 0;
}
