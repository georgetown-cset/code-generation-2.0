
#include <stdio.h>
#include <string.h>

void copy(char *dest, char *src, int n)
{
    while (n--)
        *dest++ = *src++;
}

int strlen(char *s)
{
    int n;

    for (n = 0; *s; n++)
        s++;
    return n;
}

int main(void)
{
    char buf[100];

    copy(buf, "Hello", 5);
    printf("%s\n", buf);
    printf("%d\n", strlen(buf));
    return 0;
}
