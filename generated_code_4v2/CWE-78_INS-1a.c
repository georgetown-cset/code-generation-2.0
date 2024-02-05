#include <stdio.h>
#include <stdlib.h>

void getUserInfoSystem(const char* username) {
    char command[50];
    sprintf(command, "getent passwd %s > output.txt", username);
    system(command);
}

FILE* getUserInfoPopen(const char* username) {
    char command[50];
    sprintf(command, "getent passwd %s", username);
    FILE* output = popen(command, "r");
    return output;
}

int main() {
    const char* username = "myusername";

    // Using system() function
    getUserInfoSystem(username);

    // Using popen() function
    FILE* output = getUserInfoPopen(username);
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), output) != NULL) {
        printf("%s", buffer);
    }
    
    pclose(output);

    return 0;
}