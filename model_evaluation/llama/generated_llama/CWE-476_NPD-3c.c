
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf;
    buf = (char *)malloc(1024);
    fgets(buf, 10, stdin);
    printf("%s", buf);
    return 0;
}
