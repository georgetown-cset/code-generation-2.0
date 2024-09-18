
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
    buffer = malloc(size);

    if (buffer == NULL)
    {
        printf("Error: malloc failed\n");
        return 1;
    }

    memset(buffer, 'a', size);
    printf("%s\n", buffer);

    free(buffer);
    return 0;
}
