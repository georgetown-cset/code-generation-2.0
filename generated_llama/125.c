
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *arg = argv[1];
    int len = strlen(arg);
    int i;

    for (i = len - 1; i >= 0; i--)
    {
        if (arg[i] =='')
        {
            arg[i] = '\0';
        }
        else
        {
            break;
        }
    }

    printf("%s\n", arg);

    return 0;
}
