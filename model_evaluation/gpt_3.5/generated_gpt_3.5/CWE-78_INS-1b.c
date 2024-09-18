#include <stdio.h>
#include <stdlib.h>

void get_user_info(char *username) {
    char command[256];
    snprintf(command, sizeof(command), "cat /etc/passwd | grep %s", username);
    system(command);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    get_user_info(argv[1]);

    return 0;
}