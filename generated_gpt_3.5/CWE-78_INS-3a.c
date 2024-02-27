#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Declare a variable to hold the command
    char cmd[50];

    // Create the command
    sprintf(cmd, "ls %s", "/home");  // Replace /home with your directory

    // Execute the command
    int status = system(cmd);
    if(status == -1) {
        printf("system() function failed\n");
        return -1;
    }

    return 0;
}