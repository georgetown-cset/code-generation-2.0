#include <stdio.h>
#include <stdlib.h>

int main() {
    char *command;
    command = malloc(128 * sizeof(char));

    // Use the print function to create the string that is passed to the system function
    printf("Enter the command to execute: ");
    scanf("%s", command);

    // Execute the ls command using the system function
    system(command);

    free(command);
    return 0;
}