#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Error forking process");
        exit(1);
    } else if (pid > 0) { // Parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Exit status: %d\n", WEXITSTATUS(status));
    } else { // Child process
        char command[100];
        snprintf(command, sizeof(command), "id %s", argv[1]);
        int fd[2];
        pid_t wpid;

        if (pipe(fd) < 0) {
            perror("Error creating pipe");
            exit(1);
        }

        wpid = fork();

        if (wpid > 0) { // Parent of the child that runs the command
            close(fd[0]); // Close reading end
            dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe
            execlp("/bin/sh", "/bin/sh", "-c", command, (char *)NULL);
            perror("Error executing command");
            exit(1);
        } else if (wpid == 0) { // Child that runs the command
            close(fd[1]); // Close writing end
            freopen("/dev/fd/0", "r", stdin); // Redirect stdin from pipe
            execlp("/usr/bin/id", "/usr/bin/id", argv[1], (char *)NULL);
            perror("Error executing id command");
            exit(1);
        } else { // Error forking
            close(fd[0]);
            close(fd[1]);
            waitpid(wpid, &status, 0);
            printf("Exit status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}