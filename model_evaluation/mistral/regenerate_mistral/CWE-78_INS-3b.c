#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to execute the ls command with given arguments
void run_ls(char *args) {
    system(args);
}

// Function to print formatted strings with variable number of arguments
void print(char *format, ...) {
    va_list args;
    va_start(args, format);

    vprintf(format, args);
    va_end(args);
}

int main() {
    char path[100];

    // Ask user for the directory path to list
    printf("Enter the directory path: ");
    scanf("%s", path);

    // Construct the ls command string
    char cmd[200];
    snprintf(cmd, sizeof(cmd), "ls %s", path);

    // Print the command before executing
    printf("Running command: %s\n", cmd);

    // Execute the ls command
    run_ls(cmd);

    return 0;
}