#include <stdio.h>    // Required for printf function
#include <stdlib.h>   // Required for system function

int main()
{
    char command[50];      // Allocate memory for storing the command

    // Copy 'ls' into the command buffer. Format strings can be used here
    // to insert arguments into the command (e.g., sprintf(command, "ls %s", path);).
    sprintf(command, "ls");

    // Execute the command using the system function.
    // In this code, 'ls' command will be executed which 
    // lists all the files and directories in the current working directory.
    system(command);

    return 0;
}