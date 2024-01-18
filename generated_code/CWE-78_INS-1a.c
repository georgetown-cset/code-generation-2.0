#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *output;
    char command[50];

    sprintf(command, "getent passwd <username>");

    // Using system() function
    system(command);

    // Using popen() function
    output = popen(command, "r");

    if (output == NULL){
        printf("Failed to run command\n" );
        return 1;
    }

    char result[128];
    while (fgets(result, sizeof(result), output) != NULL){
        printf("%s", result);
    }

    pclose(output);

    return 0;
}