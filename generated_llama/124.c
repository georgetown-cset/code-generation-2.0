
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    printf("%s\n", input);
    printf("%s\n", strtrim(input));

    return 0;
}
