#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cmd[128]; // Command buffer

    // Use printf to create the command string
    printf("ls\n", ""); // Print "ls" without any arguments
    strcpy(cmd, "ls"); // Copy the command string to cmd buffer

    // Execute the command using system() function
    system(cmd);

    // Use printf to create the command string with an argument
    printf("ls %s\n", "output.txt"); // Print "ls output.txt"
    strcpy(cmd, "ls "); // Copy the command string to cmd buffer
    strcat(cmd, "output.txt"); // Append the argument to the command string

    // Execute the command using system() function
    system(cmd);

    return 0;
}