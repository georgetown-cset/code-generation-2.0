#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

void search_user(char *username) {
    FILE *pipe, *pipe2;
    char buffer[MAX_BUF];
    char command[MAX_BUF];

    sprintf(command, "cat /etc/passwd | grep '%s'", username);

    pipe = popen(command, "r");

    if (!pipe) {
        perror("Error opening pipe");
        return;
    }

    while (fgets(buffer, MAX_BUF, pipe) != NULL) {
        printf("%s", buffer);
    }

    pclose(pipe);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    search_user(argv[1]);

    return 0;
}