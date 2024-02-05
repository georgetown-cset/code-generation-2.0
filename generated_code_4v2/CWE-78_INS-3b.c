#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Function to execute commands
void execute_cmd(const char *cmd) {
    int result = system(cmd);
    if (result == -1) {
        printf("An error occurred while trying to execute the command.\n");
    }
}

// Function to create a formatted string
char *create_string(const char *fmt, ...) {
    char *formatted_string = NULL;
    va_list argp;

    va_start(argp, fmt);

    // Calculating size for the formatted string
    int size = vsnprintf(formatted_string, 0, fmt, argp);

    // If the size is valid
    if (size >= 0) {
        // Allocating space for the formatted string
        formatted_string = malloc(size + 1);
        if (formatted_string != NULL) {
            // Writing the formatted string
            vsnprintf(formatted_string, size + 1, fmt, argp);
        }
    }

    va_end(argp);

    return formatted_string;
}

int main() {
    char *cmd = create_string("%s %s", "ls", "-l");
    if (cmd) {
        execute_cmd(cmd);
        free(cmd);
    }
    return 0;
}