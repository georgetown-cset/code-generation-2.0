
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf;
    int i;

    buf = (char *)malloc(1024);
    if (buf == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < 10; i++)
    {
        fgets(buf, 10, stdin);
        printf("%s", buf);
    }

    free(buf);
    return 0;
}
