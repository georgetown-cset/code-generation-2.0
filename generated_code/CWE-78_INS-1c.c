#include <stdlib.h>
#include <stdio.h>

// Function to execute the id command
int print_user_info(char *username) {
    char command[50];
    snprintf(command, sizeof(command), "id %s", username);
    int ret = system(command);
    return ret;
}

int main(int argc, char *argv[]) {

    // Checking if exactly one argument is provided
    if(argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    // Execute the command and print the exit status
    int ret = print_user_info(argv[1]);
    printf("Command exit status: %d\n", ret);

    if(ret == 0)
        printf("Command execution successful\n");
    else
        printf("Command execution failed\n");

    return 0;
}