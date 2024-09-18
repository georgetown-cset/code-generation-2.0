#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc < 3){
        printf("You must provide at least 1 command line argument.\n");
        return -1;
    }

    int index = atoi(argv[1]);

    if(index < argc - 1 && index >= 0) {
        printf("The argument at index %d is: %s \n", index, argv[index+1]);
    } else {
        printf("Index out of range.\n");
    }

    return 0;
}