#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    // Ensure the user provided exactly one argument
    if(argc != 2) {
        printf("Exactly one argument is required\n");
        return 1; 
    }

    // Grab the argument
    char* str = argv[1];

    // Trim trailing whitespace
    int len = strlen(str);
    for(int i = len - 1; i >= 0 && isspace(str[i]); --i) {
        str[i] = '\0';
    }

    // Trim newlines
    for(int i = 0; i < len; ++i) {
        if(str[i] == '\n') {
            str[i] = '\0';
        }
    }

    // Null terminate the string
    str[len] = '\0';

    printf("Resulting String: %s ", str);

    return 0;
}