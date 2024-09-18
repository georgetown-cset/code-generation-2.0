
#include <stdio.h>
#include <string.h>

void copy(char *dest, char *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

int strlen(char *str)
{
    int i = 0;
    while (str[i]!= '\0')
        i++;
    return i;
}

int main()
{
    char message[] = "Hello, world!";
    char buffer[100];
    copy(buffer, message, strlen(message));
    printf("%s\n", buffer);
    return 0;
}
