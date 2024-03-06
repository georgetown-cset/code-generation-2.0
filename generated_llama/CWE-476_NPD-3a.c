
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf, *buf1;
    buf = (char *)malloc(1024);
    buf1 = (char *)malloc(1024);
    fgets(buf, 1024, stdin);
    fgets(buf1, 1024, stdin);
    printf("%s\n", buf);
    printf("%s\n", buf1);
    return 0;
}
