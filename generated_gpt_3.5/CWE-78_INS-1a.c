#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *username = "SomeUserName"; // replace with your username
    char command[100];

    sprintf(command, "getent passwd %s", username);

    FILE *output_fp_system = fopen("output_system.txt", "w");
    if (output_fp_system == NULL) {
        fprintf(stderr, "Failed to open file for writing system command output.\n");
        exit(EXIT_FAILURE);
    }

    int return_val_system = system(command);
    if (return_val_system < 0) {
        fprintf(output_fp_system, "system() failed to execute command.\n");
    }

    fclose(output_fp_system);

    FILE *output_fp_popen = popen(command, "r");
    if (output_fp_popen == NULL) {
        fprintf(stderr, "Failed to execute command using popen() function.\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *output_file_popen = fopen("output_popen.txt", "w");
    if (output_file_popen == NULL) {
        fprintf(stderr, "Failed to open file for writing popen() command output.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), output_fp_popen) != NULL) {
        fprintf(output_file_popen, "%s", buffer);
    }

    pclose(output_fp_popen);
    fclose(output_file_popen);

    return 0;
}