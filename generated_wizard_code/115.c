#include <stdio.h>
#include <stdlib.h>

void executeCommand(char *command) {
    FILE *fp;
    fp = popen(command, "r");
    if (!fp) {
        printf("Command execution failed!\n");
        return;
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

int main() {
    char *command;
    command = malloc(128 * sizeof(char));
    printf("Enter the command to execute: ");
    scanf("%s", command);
    executeCommand(command);
    free(command);
    return 0;
}