#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* trimWhitespace(char* str) {
    // start from end of string and move to beginning
    int index, len;
    len = strlen(str);
    for(index = len - 1; index >= 0; index--) {
        if(isspace(str[index]))  // if the char is whitespace
            str[index] = '\0';    // make it null character
        else
            break;
    }
    return str;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "usage: %s arg\n", argv[0]);
        return 1;
    }
    // trimming trailing whitespace
    char* trimmedArg = trimWhitespace(argv[1]);

    printf("Argument with trailing whitespace removed: %s\n", trimmedArg);
    return 0;
}