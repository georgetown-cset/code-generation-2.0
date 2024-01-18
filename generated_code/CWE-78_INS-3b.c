#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void execute_command(const char *format, ...) {
    va_list args;
    char command[256];

    // Initialize a variable argument list
    va_start(args, format);

    // Format the string
    vsprintf(command, format, args);

    // Execute the command
    system(command);

    // Cleanup the variable argument list
    va_end(args);
}

int main() {
    // Execute ls command using the function
    execute_command("ls %s", "-l");

    return 0;
}