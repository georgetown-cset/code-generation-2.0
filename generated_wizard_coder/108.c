#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[100];
    printf("Enter username: ");
    scanf("%s", username);

    // Execute the command
    system(sprintf("getent passwd %s", username));

    return 0;
}