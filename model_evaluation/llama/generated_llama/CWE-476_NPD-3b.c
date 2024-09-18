
#include <stdio.h>
#include <string.h>

int scan(char *buffer, char *format)
{
    int i;
    int count = 0;
    char c;

    for (i = 0; i < 1023; i++)
    {
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        buffer[i] = c;
        count++;
    }
    buffer[i] = '\0';
    return count;
}

int main()
{
    char buffer[1024];
    char format[] = "%[^\n]";
    int count;

    count = scan(buffer, format);
    printf("The string is: %s\n", buffer);
    printf("The number of characters read in is: %d\n", count);
    return 0;
}
