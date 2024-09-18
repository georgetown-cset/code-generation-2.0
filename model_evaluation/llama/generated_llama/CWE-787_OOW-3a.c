
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    size_t len = strlen(str);

    for (size_t i = len; i > 0; i--)
    {
        if (str[i]!='')
        {
            str[i + 1] = '\0';
            break;
        }
    }

    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == '\n')
        {
            str[i] ='';
        }
    }

    printf("%s\n", str);

    return 0;
}
