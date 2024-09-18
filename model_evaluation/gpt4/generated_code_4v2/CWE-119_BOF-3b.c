#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, num;

    // If no arguments were passed other than program name
    if(argc == 1) {
        printf("No arguments passed except program name.\n");
        return 0;
    }

    printf("Number of arguments passed: %d\n", argc);
    printf("They are: \n");

    for(i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    //Converting string arguments to integers with atoi and printing them
    for(i = 1; i < argc; i++) {
        num = atoi(argv[i]);
        printf("%d converted from string to number\n", num);
    }

    return 0;
}