#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int execute_command(char* username) {
    char command[50];
    sprintf(command, "id %s", username);
    int exit_status = system(command);
    return WEXITSTATUS(exit_status);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: <program_name> <username>\n");
        return 1;
    }
   
    char *username = argv[1];
    int exit_status = execute_command(username);
    printf("The exit status is %d\n", exit_status);

    return 0;
}