#include <stdlib.h>
#include <stdio.h>

int main() {
    // Create a string buffer to hold the command
    char command[256];

    // Placeholders with the command to be executed
    const char *cmd = "ls";

    // Use sprintf to format the command string
    sprintf(command, "%s", cmd);

    // Execute the command using the system() function
    if (system(command) == -1) {
        fprintf(stderr, "Could not execute command\n");
        return 1;
    }

    return 0;
}