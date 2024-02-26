#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME "username"

int main() {
    FILE *output = fdopen(FILENO_STDOUT_FILENO, "w+"); // redirect output to a file pointer
    int status;
    char command[100];
    char buffer[128];

    snprintf(command, sizeof(command), "getent passwd %s > output.txt", USERNAME);
    status = system(command); // execute the command

    if (status == -1) {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    // read the output from the file pointer
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer) - 1, output);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // null-terminate the buffer
        printf("Output of the command:\n%s\n", buffer);
        fclose(output);
    } else {
        perror("Error reading output");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}