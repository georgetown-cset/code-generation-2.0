
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *command = "ls";
    char *args[] = {command, NULL};
    char *output = NULL;
    int length = 0;

    length = system(args);
    output = malloc(length + 1);
    if (output == NULL)
    {
        printf("Error: malloc failed\n");
        return 1;
    }
    length = system(args);
    output[length] = '\0';
    printf("%s\n", output);
    free(output);
    return 0;
}
