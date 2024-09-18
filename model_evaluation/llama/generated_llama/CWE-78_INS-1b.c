
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *username;
    char *command;
    char *userinfo;
    int status;
    int pid;

    if (argc!= 2)
    {
        printf("Usage: %s username\n", argv[0]);
        exit(1);
    }

    username = argv[1];

    command = malloc(strlen(username) + 10);
    sprintf(command, "cat /etc/passwd | grep %s", username);

    pid = fork();

    if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, (char *)0);
        exit(1);
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            userinfo = malloc(1024);
            read(0, userinfo, 1024);
            printf("%s\n", userinfo);
            free(userinfo);
        }
    }

    free(command);
    return 0;
}
