
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
    for (i = 0; s[i]!= '\0'; i++);
    return i;
}

int main()
{
    char buffer[100];
    char *s = "Hello";
    copy(buffer, s, strlen(s));
    printf("%s\n", buffer);
    return 0;
}
