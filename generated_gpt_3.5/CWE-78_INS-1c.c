#include <stdlib.h>
#include <stdio.h>

int getUserInfo(char* username) {
    char command[50];
    sprintf(command, "id %s", username);
    int status = system(command);
    return status;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a username as command line argument.\n");
        return 1;
    }
    int status = getUserInfo(argv[1]);
    printf("Exit status: %d\n", status);
    return 0;
}