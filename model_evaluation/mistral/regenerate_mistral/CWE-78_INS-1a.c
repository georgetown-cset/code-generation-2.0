#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        return 1;
    }

    FILE *output = tmpfile();
    int status;
    char command[128];
    snprintf(command, sizeof(command), "getent passwd %s > %s", argv[1], "output.txt");

    status = system(command);
    if (status == -1) {
        perror("Error executing command");
        fclose(output);
        return 1;
    }

    // Read the output from the file created by getent
    FILE *fp = fopen("output.txt", "r");
    if (fp == NULL) {
        perror("Error opening output file");
        fclose(output);
        return 1;
    }

    char buffer[256];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, stdout);
    }

    fclose(fp);
    fclose(output);
    return 0;
}