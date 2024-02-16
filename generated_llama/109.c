
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
    char *user_info;
    int status;
    int pid;

    if (argc!= 2)
    {
        printf("Usage: %s username\n", argv[0]);
        exit(1);
    }

    username = argv[1];
    command = "cat /etc/passwd | grep ";
    user_info = malloc(1024);

    pid = fork();

    if (pid == 0)
    {
        execlp("sh", "sh", "-c", command, username, (char *)0);
        exit(1);
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("User information:\n");
            printf("%s\n", user_info);
        }
        else
        {
            printf("Error: %s\n", strerror(WEXITSTATUS(status)));
        }
    }

    return 0;
}
