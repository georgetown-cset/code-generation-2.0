#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    char *username = argv[1];

    FILE *pipe = popen("id " username, "r");
    if (!pipe) {
        perror("popen");
        return 1;
    }

    int status = 0;
    while (fscanf(pipe, "%d", &status) != EOF) {
        if (status != 0) {
            printf("Command failed with exit status %d\n", status);
        } else {
            printf("Command succeeded with exit status %d\n", status);
        }
        break;
    }

    pclose(pipe);
    return 0;
}