#include <stdio.h>
#include <stdlib.h>

int main() {
    char *command;
    command = malloc(128);

    // Use the print function to create the string that is passed to system
    // The format string contains placeholders for the arguments
    printf("Enter the command to execute: ");
    scanf("%s", command);

    // Execute the command using the system function
    system(command);

    free(command);
    return 0;
}