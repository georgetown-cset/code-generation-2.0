
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *execute(char *cmd) {
    char *output;
    int fd[2];
    pid_t pid;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        execl("/bin/sh", "sh", "-c", cmd, (char *)0);
        exit(0);
    } else {
        close(fd[1]);
        wait(0);
        output = (char *)malloc(1000);
        read(fd[0], output, 1000);
        return output;
    }
}

int main() {
    char *output;
    char *cmd;

    cmd = "ls";
    output = execute(cmd);
    printf("%s\n", output);
    return 0;
}
