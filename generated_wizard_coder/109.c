#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execlp("cat", "cat", "/etc/passwd", (char *)NULL) < 0) {
            perror("execlp");
            exit(1);
        }
    } else {
        if (wait(&status) < 0) {
            perror("wait");
            exit(1);
        }

        if (execlp("grep", "grep", "username", (char *)NULL) < 0) {
            perror("execlp");
            exit(1);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s username\n", argv[0]);
        exit(1);
    }

    char *username = argv[1];
    char command[1024];
    sprintf(command, "cat /etc/passwd | grep %s", username);

    execute_command(command);

    return 0;
}