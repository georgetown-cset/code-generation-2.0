#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[128]; // Buffer to store the command string

    // Use printf to create the command string with the %s placeholder for the argument
    sprintf(command, "ls\0"); // Initializing the command with empty string
    printf("Executing command: %s\n", command);

    // Use system to execute the command
    system(command);

    return 0;
}