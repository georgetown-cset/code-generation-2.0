#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that takes in a command and executes it in the shell
void execute_command(char* cmd) {
    FILE* fp;
    char path[1035];

    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Failed to execute command\n");
        exit(1);
    }

    // Reading the output a line at a time
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    pclose(fp);
}

// Function that forms command and calls execute_command to execute it
void get_user_info(char* username) {
    char cmd[50] = "cat /etc/passwd | grep ";
    strcat(cmd, username);
    execute_command(cmd);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Incorrect number of arguments\n");
        return 1;
    }

    get_user_info(argv[1]);

    return 0;
}