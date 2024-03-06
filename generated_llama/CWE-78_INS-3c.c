
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *command = "ls";
    char *args[2];
    args[0] = command;
    args[1] = NULL;
    int status = system(args);
    if (status == 0)
    {
        printf("The command was successful.\n");
    }
    else
    {
        printf("The command was not successful.\n");
    }
    return 0;
}
