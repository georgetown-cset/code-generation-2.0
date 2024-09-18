
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
    printf("Executing command: %s\n", command);
    system(args);
    return 0;
}
