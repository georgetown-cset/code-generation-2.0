
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        execl("/bin/id", "id", argv[1], (char *)0);
    }
    else
    {
        wait(&status);
        printf("Exit status: %d\n", status);
    }
    return 0;
}
