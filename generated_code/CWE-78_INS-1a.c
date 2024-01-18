#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* output;
    char command[50];
    char username[30];

    printf("Enter username: ");
    scanf("%s", username);

    // Create command string
    strcpy(command, "getent passwd ");
    strcat(command, username);

    // Using system function
    printf("Using system function:\n");
    system(command);

    // Using popen function
    printf("Using popen function:\n");
    output = popen(command, "r");
    if (output == NULL) {
        printf("Unable to open pipe\n");
        return 1;
    }
    char result[1024];
    while (fgets(result, sizeof(result), output) != NULL) {
        printf("%s", result);
    }
    pclose(output);
    return 0;
}