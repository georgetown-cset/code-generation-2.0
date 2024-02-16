
#include <stdio.h>
#include <string.h>

void copy(char *dest, char *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

int strlen(char *s)
{
    int i;
    for (i = 0; s[i]!= '\0'; i++)
        ;
    return i;
}

int main(void)
{
    char buffer[100];
    copy(buffer, "Hello", 5);
    printf("%s\n", buffer);
    printf("%d\n", strlen(buffer));
    return 0;
}
