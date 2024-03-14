#include <stdio.h>
#include <stdlib.h>

int run_id_command(char *username) {
    char command[50];
    sprintf(command, "id %s", username);
    
    int exit_status = system(command);
    
    return exit_status;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }
    
    char *username = argv[1];
    
    int exit_status = run_id_command(username);
    
    printf("Exit status of the id command for user %s: %d\n", username, exit_status);
    
    return 0;
}