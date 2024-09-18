
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    char *input = argv[1];
    printf("Input: %s\n", input);
    printf("Trimmed: %s\n", strtrim(input));
    exit(0);
}

char *strtrim(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    *(end + 1) = 0;

    return str;
}
