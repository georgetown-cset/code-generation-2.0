#include <stdio.h>
#include <stdlib.h>

void getUserInfo(char* username){
    char command[50];
    sprintf(command, "cat /etc/passwd | grep %s", username);
    system(command);
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }
    getUserInfo(argv[1]);
    return 0;
}