#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        return 1;
    }

    int status;
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        char command[100];
        snprintf(command, sizeof(command), "id %s", argv[1]);
        system(command);
        exit(0);
    } else if (pid > 0) {
        // Parent process
        wait(&status);
    } else {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    printf("Exit status: %d\n", WEXITSTATUS(status));
    return 0;
}