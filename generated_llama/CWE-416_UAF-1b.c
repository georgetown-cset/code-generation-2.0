
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int size;
    char *buffer;

    if (argc!= 2)
    {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    size = atoi(argv[1]);
    if (size <= 0)
    {
        printf("Invalid size: %s\n", argv[1]);
        return 1;
    }

    buffer = malloc(size);
    if (buffer == NULL)
    {
        printf("Out of memory\n");
        return 1;
    }

    memset(buffer, 'a', size);
    printf("Buffer contents: %s\n", buffer);

    free(buffer);
    return 0;
}
